
outdir=/data/alice/mjongerh/alice/data/BatchTest/
if [ ! -d ${outdir} ]
then
  mkdir -p ${outdir}
  mkdir -p ${outdir}/logs/
fi

scriptdir=/data/alice/mjongerh/alice/DelphesO2/examples/scripts/
for i in {1..2}
do
	cp ${scriptdir}runbatch.sh ${outdir}runbatch${i}.sh
	cd ${outdir}
	echo ${i}
	qsub -o ${outdir}/logs/logOut -e ${outdir}/logs/logErr -q short runbatch${i}.sh
done

cd -