package com.jimwobser

import java.io.BufferedReader
import java.io.FileReader
import java.math.BigInteger

fun main(args: Array<String>){
    val inputs = ArrayList<String>()
    ingest("d25.input", inputs)
    // Overflows a signed 32-bit int, so have to convert to unsigned.
    println("Sum: ${inputs.map({parseLine(it).toUInt()}).sum()}")
//    inputs.forEach{println(it)}
//    val snafuSum: BigInteger = inputs.map({parseLine(it).toBigInteger()}).sumOf { it }
//    println("Snafu Sum: $snafuSum")

}

fun parseLine(line: String): Int{
    if(line.isEmpty()) return 0
    var total = 0
    var idx = line.length - 1
    var base = 1
    while(idx >= 0){
        val c = line.get(idx)
        val v = when (c){
            '=' -> -2
            '-' -> -1
            else -> c.toString().toInt()
        }
        total += (base * v)
        base *= 5
        idx--
    }
    return total
}

fun ingest(name: String, dest: ArrayList<String> ){
    val file = BufferedReader(FileReader(name))
    var input = file.readLine()
    while(input != null){
        dest.add(input)
        input = file.readLine()
    }
    file.close()
}

class D25 {

}