string=$1
len=`echo $1|wc -c`
while [ $len -gt 0 ]
do
temp=`echo $1|cut -c $len`
rev=`echo $rev$temp`
len=`expr $len - 1`
done
if [ ``$string`` = ``$rev`` ]
then
echo $string is a Pallindrome
else
echo $string is not a Pallindrome
fi

