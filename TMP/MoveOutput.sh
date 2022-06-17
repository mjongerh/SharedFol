outdir=/data/alice/mjongerh/alice/data/pp14TeV_bbbar_50M_2T/
j=0
for i in {10460010..10460011} #83
do
	#statements
	for f in {0..2} #199
	do
	#statements
	echo ${outdir}Job_${i}/AODRun5.${f}.root
	echo ${outdir}AODRun5.${j}.root
	if [ -f ${outdir}Job_${i}/AODRun5.${f}.root ]; then 
        	cp ${outdir}Job_${i}/AODRun5.${f}.root ${outdir}AODRun5.${j}.root
			let j+=1
	fi
    done

done
