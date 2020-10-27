read n
a=0
b=1
echo First $n fibonacci numbers are
if [ $n -eq 1 ]
then 
echo 0
else
echo 0
echo 1
i=2
while [ $i -lt $n ]
do
c=`expr $a + $b`
echo $c
a=$b
b=$c
i=`expr $i + 1`
done
fi

