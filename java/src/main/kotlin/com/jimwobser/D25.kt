package com.jimwobser

import java.io.BufferedReader
import java.io.FileReader
import java.math.BigInteger
import kotlin.math.ceil
import kotlin.math.floor
import kotlin.math.ln
import kotlin.math.pow

fun main(args: Array<String>){
    println("hello world")
    val inputs = ArrayList<String>()
    ingest("d25.input", inputs)
    for(s in inputs){
        println("$s \t : ${parseLine(s)}")
    }
    val inputarrays = inputs.map { parseLine(it) }
    val output = inputarrays.reduce { a, b -> addIntArray(a, b) }
    println(output)
    for(i in 0 until output.size - 1){
        while(output[i] > 2){
            output[i+1] += 1
            output[i] -= 5
        }
        while(output[i] < -2){
            output[i+1] -= 1
            output[i] += 5
        }
    }
    println(output)
    val sb = StringBuilder()
    for(v in output.reversed()){
        sb.append(
            when(v){
                -2 -> '='
                -1 -> '-'
                else -> v
            }
        )
    }
    println(sb.toString())
//    println(inputarrays.reduce{a,b -> addIntArray(a,b)})
    /*
    println(inputs)
    println(inputs.map{ parseLine(it)})
    // Overflows a signed 32-bit int, so have to convert to unsigned.
    val total = inputs.map({parseLine(it).toUInt()}).sum()
    println("Sum: $total")
    val totalBase5 = convertToBaseFive(total)
    val offsetBase5 = offsetBaseFive(totalBase5)
    println(convertToSNAFU(offsetBase5))
//    inputs.forEach{println(it)}
//    val snafuSum: BigInteger = inputs.map({parseLine(it).toBigInteger()}).sumOf { it }
//    println("Snafu Sum: $snafuSum")

     */

}

// Java overload for UInt type
fun convertToBaseFive(n: Int): ArrayList<Int>{
    return convertToBaseFive(n.toUInt())
}

fun convertToBaseFive(n: UInt): ArrayList<Int>{
    var w = n
    val order = (ceil(ln(n.toDouble()) / ln(5.0)) ).toInt()
    var result = MutableList(order + 1){0} as ArrayList<Int>
    for(i in 1 .. order){
        val p = 5.0.pow(order - i).toUInt()
        result[i] = (w / p).toInt()
        w -= result[i].toUInt() * p
    }
    return result
}

fun offsetBaseFive(v: ArrayList<Int>): ArrayList<Int>{
    while(v.any{it > 2}) {
        for (i in 1 until v.size) {
            if (v[i] > 2) {
                v[i - 1] += 1
                v[i] -= 5
            }
        }
    }
    return v
}


fun convertToSNAFU(v: ArrayList<Int>): String{
    var result = StringBuilder()
    for(i in v){
        result.append(
        when(i){
            -2 -> '='
            -1 -> '-'
            else -> i
        } )
    }
    return result.toString()
}

inline fun addIntArray(a: ArrayList<Int>, b: ArrayList<Int>): ArrayList<Int> {
    var result = ArrayList<Int>()
    if( a.size > b.size) {
        a.forEach { result.add(it) }
        for(i in 0 until b.size){
            result[i] += b[i]
        }
    } else {
        b.forEach(){result.add(it)}
        for(i in 0 until a.size){
            result[i] += a[i]
        }
    }
    return result
}
fun parseLine(line: String): ArrayList<Int> {
    val result = ArrayList<Int>()
    for (i in line.length - 1 downTo 0) {
        val c = line.get(i)
        result.add(
            when (c) {
                '=' -> -2
                '-' -> -1
                else -> c.toString().toInt() } )
    }
    return result
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