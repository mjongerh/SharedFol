if [ $# -lt 3 ]
then
  echo "Specify outdir in dcache, and job array range"
  exit 
fi

outdir=/dcache/alice/hohbern/${1}/
if [ ! -d ${outdir} ]
then
  mkdir -p ${outdir}
  mkdir -p ${outdir}/logs/
fi
cp run_stratrack.sh ${outdir}
cp config_custom_Pythia.cfg ${outdir}
cp configPythia.ini ${outdir}
cp generator_pythia8_gun.C ${outdir}
cp RecoDecay.h ${outdir}
cp pp13.cmnd ${outdir}
cp run_strangenesstracking_01.C ${outdir}
cp trigger_multiplicity.C ${outdir}
cp runbatch.sh ${outdir}
cd ${outdir}
qsub -o ${outdir}/logs/logOut -e ${outdir}/logs/logErr -q short -t ${2}-${3} runbatch.sh
cd -




