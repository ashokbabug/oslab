read n
i=2
echo Prime Numbers upto $n are
while [ $i -le $n ]
do
c=0
j=1
while [ $j -le $i ]
do
val=`expr $i % $j`
if [ $val -eq 0 ]
then
c=`expr $c + 1`
fi
j=`expr $j + 1`
done
if [ $c -eq 2 ]
then
numbers=`echo $numbers $i`
fi
i=`expr $i + 1`
done
echo $numbers
