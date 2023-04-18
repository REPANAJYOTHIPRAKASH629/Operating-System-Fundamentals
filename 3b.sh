echo "Enter the basic salary:"
read basic
if [ $basic -lt 1500 ]
then
    hra=$(echo "scale=2; $basic * 0.1" | bc)
    da=$(echo "scale=2; $basic * 0.9" | bc)
else
    hra=500
    da=$(echo "scale=2; $basic * 0.98" | bc)
fi
gross_salary=$(echo "scale=2; $basic + $hra + $da" | bc)
echo "Gross salary: $gross_salary"
