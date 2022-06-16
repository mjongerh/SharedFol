outdir=/data/alice/mjongerh/alice/data/BatchTest/
if [ ! -d ${outdir} ]
then
  mkdir -p ${outdir}
  mkdir -p ${outdir}/logs/
fi

scriptdir=/data/alice/mjongerh/alice/SharedFol/TMP
for i in {1..2}
do
	cd ${scriptdir}
	echo ${i}
	qsub -o ${outdir}/logs/logOut_${i} -e ${outdir}/logs/logErr${i} -q short runbatch.sh
	sleep 10
	cd ${currentdir}
done
