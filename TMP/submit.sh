
outdir=/data/alice/mjongerh/alice/data/BatchTest/
if [ ! -d ${outdir} ]
then
  mkdir -p ${outdir}
  mkdir -p ${outdir}/logs/
fi

cp runbatch.sh ${outdir}
cd ${outdir}
for i in {1..2}
do
	echo ${i}
	qsub -o ${outdir}/logs/logOut -e ${outdir}/logs/logErr -q short runbatch.sh
done

cd -