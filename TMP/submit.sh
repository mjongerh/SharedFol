#outdir=/data/alice/mjongerh/alice/data/pp14TeV_bbbar_50M_2T
outdir=/data/alice/mjongerh/alice/data/Lb_BRtest
if [ ! -d ${outdir} ]
then
  mkdir -p ${outdir}
  mkdir -p ${outdir}/logs/
fi

scriptdir=/data/alice/mjongerh/alice/SharedFol/TMP
for i in {1..1}
do
	cd ${scriptdir}
	echo ${i}
	qsub -o ${outdir}/logs/logOut_${i} -e ${outdir}/logs/logErr${i} -q generic7 runbatch.sh
	cd ${currentdir}
	sleep 17
done
