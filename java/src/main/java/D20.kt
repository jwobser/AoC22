import java.io.BufferedReader
import java.io.FileReader
import kotlin.collections.ArrayList

val LISTSIZE:Int = 5000

fun main(args: Array<String>){
    if(args.size > 0){
        if(args[0].compareTo("-e") == 0){
            example()
            return
        }
    }
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
    println("Zero index: $zeroOffset")
    var sum = 0
    for(k in listOf<Int>(1001, 2001, 3001)){
        val node = inputs.find{it.idx == (k + zeroOffset) % 5000}!!
        println("$k: ${node.value}")
        sum += node.value
    }
//    println(inputs.toString())
    inputs.printByIndex()
    println("Sum of 1000, 2000, 3000th value after zero: $sum")


}

fun example(){
    println("Running Example")
    val values = listOf<Int>(1,2,-3,3,-2,0,4)
    val inputs = ArrayList<CoordinateNode>()
    for(i in 0..6){
        inputs.add(CoordinateNode(values[i],i))
    }
    for(i in 0..6){
        inputs.printByIndex()
        val offset = inputs[i].value
        var destIdx = inputs[i].getNewidx()
        var sourceIdx = inputs[i].idx
        println("Current: $sourceIdx, Destination: $destIdx")
        if (destIdx - sourceIdx > 0) {
            // Move towards end
            val op = fun(n: CoordinateNode) {
                if (n.idx <= sourceIdx || n.idx > destIdx) return
                n.idx -= 1
            }
            inputs.forEach(op)
        } else {
            // Move towards front
            val op = fun(n: CoordinateNode) {
                if (n.idx >= sourceIdx || n.idx < destIdx) return
                n.idx += 1
            }
            inputs.forEach(op)
        }
        inputs[i].idx = destIdx
    }
    inputs.printByIndex()
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

fun ArrayList<CoordinateNode>.printByIndex(): Unit{
    var l = this.toMutableList()
    l.sortBy { n -> n.idx }
    println(l.toString())
}

data class CoordinateNode(val value: Int, var idx: Int){
    fun getOffset(): Int{
        var offset = value
        while(offset < (-1 * LISTSIZE)){
            offset += LISTSIZE
        }
        while(offset >= LISTSIZE){
            offset -= LISTSIZE
        }
        return offset
    }

    fun getNewidx(): Int{
        var destCandidate = idx + this.getOffset()
        // Handle Wrap arounds, where moving to the back of the list
        // doesn't actually change relative positioning
        if(destCandidate >= LISTSIZE){
            destCandidate -= LISTSIZE
            destCandidate += 1
        } else if(destCandidate < 0){
            destCandidate += LISTSIZE
            destCandidate -= 1
        } else if(destCandidate == 0){
            destCandidate += (LISTSIZE - 1)
        }

        return destCandidate
    }

    override fun toString(): String{
        return "($value, $idx)"
//        return value.toString()
    }
}