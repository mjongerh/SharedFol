outdir=/data/alice/mjongerh/alice/data/BatchTest/
if [ ! -d ${outdir} ]
then
  mkdir -p ${outdir}
  mkdir -p ${outdir}/logs/
fi

scriptdir=/data/alice/mjongerh/alice/DelphesO2/examples/scripts/
for i in {1..2}
do
	cd ${scriptdir}
	echo ${i}
	qsub -o ${outdir}/logs/logOut_${i} -e ${outdir}/logs/logErr${i} -q short runbatch.sh
	cd ${currentdir}
done
