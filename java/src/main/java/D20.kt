import java.io.BufferedReader
import java.io.FileReader
import java.util.*
import kotlin.collections.ArrayList

fun main(args: Array<String>){
    var inputs = ArrayList<CoordinateNode>()
    ingest("d20.input", inputs)
//    inputs.forEach { println(it) }
    println("Linecount: ${inputs.size}")
    println("Max: ${inputs.maxBy { it.value }}")
    println("Min: ${inputs.minBy { it.value }}")

    println("Zero index: ${inputs.find{it.value == 0}!!.idx}")
    var inset = inputs.toSet()
    var intlist = LinkedList<Int>()
    inputs.forEach {intlist.add(it.value)}
    println(intlist.joinToString(",","[","]"))
    println("Set size: ${inset.size}")
    println("All unique: ${inset.size == inputs.size}")
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

    fun getNewidx(){
        (idx + this.getOffset()) % 5000
    }
}