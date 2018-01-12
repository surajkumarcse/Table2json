curl https://www.cleartrip.com/trains/stations/$1 | cat>temp.txt
grep "<td" temp.txt | cat>traintable.txt
gcc -o codeExtractionTrain codeExtractionTrain.c
./codeExtractionTrain
