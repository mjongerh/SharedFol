currentdir=/data/alice/mjongerh/alice/SharedFol/TMP/
outdir=/data/alice/mjongerh/alice/data/BatchTest/
if [ ! -d ${outdir} ]
then
  mkdir -p ${outdir}
  mkdir -p ${outdir}/logs/
fi

scriptdir=/data/alice/mjongerh/alice/DelphesO2/examples/scripts/
for i in {${1}..${2}}
do
	mkdir -p ${outdir}/Job${i}/
	cp runbatch.sh ${outdir}/Job${i}/runbatch.sh
	cd ${outdir}/Job${i}/
	echo ${i}
	qsub -o ${outdir}/Job${i}/logs/logOut -e ${outdir}/Job${i}/logs/logErr -q short runbatch.sh
	cd ${currentdir}
done
