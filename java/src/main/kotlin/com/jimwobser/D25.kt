package com.jimwobser

import java.io.BufferedReader
import java.io.FileReader

fun main(args: Array<String>) {
    val inputs = ArrayList<String>()
    ingest("d25.input", inputs)
    val output = inputs.map { parseLine(it) }.reduce(::addIntArray)
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
}

fun addIntArray(a: ArrayList<Int>, b: ArrayList<Int>): ArrayList<Int> {
    val result = ArrayList<Int>()
    if( a.size > b.size) {
        a.forEach { result.add(it) }
        for(i in 0 until b.size){
            result[i] += b[i]
        }
    } else {
        b.forEach {result.add(it)}
        for(i in 0 until a.size){
            result[i] += a[i]
        }
    }
    return result
}
fun parseLine(line: String): ArrayList<Int> {
    val result = ArrayList<Int>()
    for (c in line.reversed()) {
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

class D25