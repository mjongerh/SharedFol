if [ $# -lt 3 ]
then
  echo "Specify outdir in dcache, and job array range"
  exit 
fi

outdir=/data/alice/mjongerh/alice/data/${1}/
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