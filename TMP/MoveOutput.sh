outdir=/data/alice/mjongerh/alice/data/pp14TeV_bbbar_50M_2T/
j=0
for i in {10460010..10460083} #83
do
	#statements
	for f in {0..199} #199
	do
	#statements
	echo ${outdir}Job_${i}/AODRun5.${f}.root
	echo ${outdir}AODRun5.${j}.root
	if [ -f ${outdir}Job_${i}/AODRun5.${f}.root ]; then 
        	mv ${outdir}Job_${i}/AODRun5.${f}.root ${outdir}AODRun5.${j}.root
			let j+=1
	fi
    done
	rm ${outdir}Job_${i}/summary.txt
	rm ${outdir}Job_${i}/
done
