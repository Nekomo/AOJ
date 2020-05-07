package sample

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
//array,arraysize,distance
fun insertionSortShellCustom(A:IntArray,n:Int,g:Int):Int
{
    var cnt=0
    for(i in g..n-1){
        var v=A[i]
        var j=i-g
        while(j>=0 && A[j]>v){
            A[j+g]=A[j]
            j=j-g
            cnt+=1
        }
        A[j+g]=v
        //A.println_splitself()
    }
    return cnt
}

fun shellSort(A:IntArray,n:Int):Int
{
    var cnt=0
    var Garraylist= arrayListOf<Int>()
    var h=1
    if(n<=1)
    {
        Garraylist.add(1)
    }
    while(h<n)
    {
        Garraylist.add(h)
        h=h*3+1
    }
    var G= Garraylist.reversed().toIntArray()
    var m=G.size

    println(m)
    G.println_splitself()
    for (i in 0..m-1)
    {
        //A.print_splitself()
        //println("${n},${G[i]}")
        cnt+=insertionSortShellCustom(A,n,G[i])
    }
    return cnt
}

fun main(args:Array<String>)
{
    var n=readLine()!!.toInt()
    var arrlist=ArrayList<Int>()
    for(i in 0..n-1)
    {
        //println(i)
        arrlist.add(readLine()!!.toInt())
    }
    var arr=arrlist.toIntArray()
    var cnt=shellSort(arr,n)
    println("$cnt")
    for(e in arr)
    {
        println(e)
    }
}