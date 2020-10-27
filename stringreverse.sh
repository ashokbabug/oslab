len=`echo $1|wc -c`
##echo Length of $1 is $len
string=$1
while [ $len -gt 0 ]
do
temp=`echo $1|cut -c $len`
rev=`echo $rev$temp`
len=`expr $len - 1`
done
echo Reverse of $string is $rev
