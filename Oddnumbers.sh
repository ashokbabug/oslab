read n
echo Odd numbers upto $n are
i=1
while [ $i -le $n ]
do
numbers=`echo $numbers $i`
i=`expr $i + 2`
done
echo $numbers
