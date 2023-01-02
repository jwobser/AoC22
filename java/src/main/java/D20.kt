import java.io.BufferedReader
import java.io.FileReader
import java.util.*
import kotlin.collections.ArrayList

fun main(args: Array<String>){
    var inputs = ArrayList<CoordinateNode>()
    ingest("d20.input", inputs)

    var destIdx = inputs[0].getNewidx()
    var sourceIdx = inputs[0].idx
    println("Current: $sourceIdx, Destination: $destIdx")
    if(destIdx - sourceIdx > 0){
        // Move towards end
        println("Moving towards end")
        var op = fun(n: CoordinateNode){
            if(n.idx <= sourceIdx || n.idx > destIdx) return
            n.idx -= 1
        }
        inputs.forEach(op)
        inputs[0].idx = destIdx
        inputs.forEach{print("${it.idx}, ")}
        print('\n')
    } else {
        // Move towards front
    }

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
}