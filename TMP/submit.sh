outdir=/data/alice/mjongerh/alice/data/BatchTest/
if [ ! -d ${outdir} ]
then
  mkdir -p ${outdir}
  mkdir -p ${outdir}/logs/
fi

scriptdir=/data/alice/mjongerh/alice/SharedFol/TMP
for i in {1..50}
do
	cd ${scriptdir}
	echo ${i}
	qsub -o ${outdir}/logs/logOut_${i} -e ${outdir}/logs/logErr${i} -q long7 runbatch.sh
	cd ${currentdir}
	sleep 17
done
