echo "Outputs present in outputs.txt in current directory."
echo "Parameter 1: incr/decr"
echo "Parameter 2: factor of incr/decr"

make
./a.out "$1" "$2" > outputs.txt
python3 analysis.py "$1" "$2" #"$3"