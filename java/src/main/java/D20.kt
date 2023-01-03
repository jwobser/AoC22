import java.io.BufferedReader
import java.io.FileReader
import java.util.*
import kotlin.collections.ArrayList

fun main(args: Array<String>){
    var inputs = ArrayList<CoordinateNode>()
    ingest("d20.input", inputs)

    // O(N^2) loop
    for(i in 0..4999) {
        var destIdx = inputs[i].getNewidx()
        var sourceIdx = inputs[i].idx
        println("Current: $sourceIdx, Destination: $destIdx")
        if (destIdx - sourceIdx > 0) {
            // Move towards end
            var op = fun(n: CoordinateNode) {
                if (n.idx <= sourceIdx || n.idx > destIdx) return
                n.idx -= 1
            }
            inputs.forEach(op)
        } else {
            // Move towards front
            var op = fun(n: CoordinateNode) {
                if (n.idx >= sourceIdx || n.idx < destIdx) return
                n.idx += 1
            }
            inputs.forEach(op)
        }
        inputs[i].idx = destIdx
    }
    val setofidxs: MutableSet<Int> = mutableSetOf()
    inputs.forEach {setofidxs.add(it.idx)}
    assert(setofidxs.size == 5000)

//    inputs.sortBy{it.idx}
    val zeroOffset = inputs.find{it.value == 0}!!.idx
    var sum = 0
    for(k in listOf<Int>(1000, 2000, 3000)){
        val node = inputs.find{it.idx == (k + zeroOffset) % 5000}!!
        println("$k: ${node.value}")
        sum += node.value
    }
    println(inputs.toString())
    println("Sum of 1000, 2000, 3000th value after zero: $sum")


}


fun ingest(name: String, dest: ArrayList<CoordinateNode> ){
    val file = BufferedReader(FileReader(name))
    var input = file.readLine()
    var linecount: Int = 0
    while(input != null){
        dest.add(CoordinateNode(input.toInt(), linecount))
        input = file.readLine()
        linecount++
    }
    file.close()
}

data class CoordinateNode(val value: Int, var idx: Int){
    fun getOffset(): Int{
        var offset = value
        while(offset < 0){
            offset += 5000
        }
        while(offset >= 5000){
            offset -= 5000
        }
        return offset
    }

    fun getNewidx(): Int{
        return (idx + this.getOffset()) % 5000
    }

    override fun toString(): String{
        return "($value, $idx)"
    }
}