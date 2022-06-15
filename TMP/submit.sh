if [ $# -lt 3 ]
then
  echo "Specify outdir in dcache, and job array range"
  exit 
fi

outdir=/dcache/alice/mjongerh/${1}/
if [ ! -d ${outdir} ]
then
  mkdir -p ${outdir}
  mkdir -p ${outdir}/logs/
fi

cp runbatch.sh ${outdir}
cd ${outdir}
qsub -o ${outdir}/logs/logOut -e ${outdir}/logs/logErr -q short -t ${2}-${3} runbatch.sh
cd -




