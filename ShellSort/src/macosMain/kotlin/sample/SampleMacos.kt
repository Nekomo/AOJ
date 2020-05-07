package sample
import java.util.*

//基本メソッド
fun <T>MutableList<T>.swap(i:Int, j:Int){
    var tmp = this[i]
    this[i]=this[j]
    this[j]=tmp
}
fun IntArray.swap(i:Int,j:Int){
    var tmp = this[i]
    this[i]=this[j]
    this[j]=tmp
}
fun CharArray.swap(i:Int,j:Int){
    var tmp = this[i]
    this[i]=this[j]
    this[j]=tmp
}
fun IntArray.print_splitself(){
    this.forEach { it->print(it) ;print(" ")}
}
fun IntArray.println_splitself(){
    this.forEach { it->print(it) ;print(" ")}
    println()
}
fun CharArray.print_splitself(){
    this.forEach { it->print(it) ;print(" ")}
}
fun CharArray.println_splitself(){
    this.forEach { it->print(it) ;print(" ")}
    println()
}

fun insertionSort(A:IntArray,n:Int,g:Int)
{
    for i in g downto n-1{

    }
}

fun hello(): String = "Hello, Kotlin/Native!"

fun main() {

}
