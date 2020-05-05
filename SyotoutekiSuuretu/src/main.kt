import java.util.*

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
fun bubbleSort(array:IntArray):Int
{
    var swapflag=true;
    var swapcnt=0
    while(swapflag) {
        swapflag=false
        for (i in array.size - 2 downTo 0) {
            if (array[i] > array[i + 1]) {
                array.swap(i, i + 1)
                swapcnt+=1
                swapflag = true
            }
        }
    }
    array.forEach { it->print(it) ;print(" ")}
    println()
    return swapcnt
}
fun selectionSort(array:IntArray):Int
{
    var swapcnt=0
    for (i in 0 until array.size-1){
        var min=array[i]
        var mindex=i
        for (j in i+1 until array.size) {
            //print(j)
            if (min> array[j]) {
                min=array[j]
                mindex=j
            }
        }
        if (i!=mindex) {
            array.swap(i, mindex)
            swapcnt+=1
        }
    }
    //array.forEach { it->print(it) ;print(" ")}
    println()
    return swapcnt
}
fun bubbleSortCustom(charray:CharArray,iarray:IntArray):CharArray
{
    var swapflag=true;
    var swapcnt=0
    while(swapflag) {
        swapflag=false
        for (i in iarray.size-1 downTo 1) {
            if (iarray[i-1] > iarray[i]) {
                iarray.swap(i, i -1)
                charray.swap(i,i - 1)
                swapcnt+=1
                swapflag = true
                //println("$i,${i-1}")
                //iarray.println_splitself()
                //charray.println_splitself()
                //println()
            }
        }
    }
    //iarray.println_splitself()
    //charray.println_splitself()
    for(i in iarray.indices)
    {
        print(charray[i])
        print(iarray[i])
        if(i==iarray.size-1)break
        print(" ")
    }
    println()
    return charray
}
fun selectionSortCustom(charray:CharArray,iarray:IntArray):CharArray
{
    var swapcnt=0
    for (i in 0 until iarray.size-1){
        var min=iarray[i]
        var mindex=i
        for (j in i+1 until iarray.size) {
            //print(j)
            if (min> iarray[j]) {
                min=iarray[j]
                mindex=j
            }
        }
        if (i!=mindex) {
            iarray.swap(i, mindex)
            charray.swap(i, mindex)

            //iarray.forEach { it->print(it) ;print(" ")};println()
            //charray.forEach { it->print(it) ;print(" ")};println()
            swapcnt+=1
        }
    }
    for(i in iarray.indices)
    {
        print(charray[i])
        print(iarray[i])
        if(i==iarray.size-1)break
        print(" ")
    }
    println()
    return charray
}
fun main(args:Array<String>){
    readLine()

    var line = readLine()!!.split(' ').joinToString("")
    var charray=line.filterIndexed{i,_->i.toInt()%2==0}.toCharArray()
    var numarray=line.filterIndexed{i,_->i.toInt()%2==1}.map{Integer.parseInt(it.toString())}.toIntArray()
    var sortedCharArray= bubbleSortCustom(charray.clone(),numarray.clone())
    //charray.forEach { it->print(it) ;print(" ")};println()
    //numarray.forEach { it->print(it) ;print(" ")};println()
    //println()
    //sortedCharArray.forEach { it->print(it) ;print(" ")};println()
    println(if(isStableSortedArray(numarray,charray,sortedCharArray ))"Stable" else "Not stable")

    //println()
    sortedCharArray= selectionSortCustom(charray.clone(),numarray.clone())
    //sortedCharArray.forEach { it->print(it) ;print(" ")};println()
    println(if(isStableSortedArray(numarray,charray,sortedCharArray ))"Stable" else "Not stable")
}
fun isStableSortedArray(_uIA:IntArray,_uCA:CharArray,sortedCharray:CharArray):Boolean
{
    var unsortedCharArray = _uCA.clone().toMutableList()
    var unsortedIntArray = _uIA.clone().toMutableList()
    var motonosize=unsortedIntArray.size
    for(i in 0 until motonosize)
    {
        var min=unsortedIntArray.min()
        var mindex=unsortedIntArray.indexOf(min)
        //minの中で最も左の文字と、ソート済み配列の最小値をチェエエエック
        //print("$i,$mindex")
        if(unsortedCharArray[mindex]!=sortedCharray[i])
        {
            //println(" ... Fail!! ${mindex},${i}   ${unsortedCharArray[mindex]},${sortedCharray[i]}")
            return false
        }
        else
        {
            //一度見たヤツは削除
            unsortedIntArray.removeAt(mindex)
            unsortedCharArray.removeAt(mindex)
        }
    }
    return true
}