#!/bin/bash
eval $(alienv printenv VO_ALICE@O2::nightly-20210710-1)
cd ${TMPDIR}
echo ${TMPDIR}
echo ${PBS_O_WORKDIR}

outdir=${PBS_O_WORKDIR}/job_${PBS_ARRAYID}

mkdir -p ${outdir}

cp ${PBS_O_WORKDIR}/run_stratrack.sh ${TMPDIR}
cp ${PBS_O_WORKDIR}/config_custom_Pythia.cfg ${TMPDIR}
cp ${PBS_O_WORKDIR}/configPythia.ini ${TMPDIR}
cp ${PBS_O_WORKDIR}/generator_pythia8_gun.C ${TMPDIR}
cp ${PBS_O_WORKDIR}/RecoDecay.h ${TMPDIR}
cp ${PBS_O_WORKDIR}/pp13.cmnd ${TMPDIR}
cp ${PBS_O_WORKDIR}/run_strangenesstracking_01.C ${TMPDIR}
cp ${PBS_O_WORKDIR}/trigger_multiplicity.C ${TMPDIR}

source run_stratrack.sh
root.exe -q -b run_strangenesstracking_01.C+
if [ ! -f histooutput.root ]; then
        echo "Failed, trying again"
        root.exe -q -b run_strangenesstracking_01.C+
fi
if [ ! -f histooutput.root ]; then
        echo "Failed yet again. Third time's the charm"
        root.exe -q -b run_strangenesstracking_01.C+
fi
if [ ! -f histooutput.root ]; then
        echo "Failed yet again. Third time's the charm"
        root.exe -q -b run_strangenesstracking_01.C+
fi
if [ ! -f histooutput.root ]; then
        echo "Forget it. Clean tree output up, this is bogus, sorry"
        rm treeoutput.root
fi
echo "Doing master cleanup"
rm o2sim_Kine.root
rm o2sim_HitsTRK.root
rm o2sim.root
rm run_strangenesstracking_01_C.d
rm run_strangenesstracking_01_C.so
rm o2sim_par.root
rm o2sim_geometry.root
rm o2sim_MCHeader.root
rm o2sim_configuration.ini
rm run_strangenesstracking_01_C_ACLiC_dict_rdict.pcm
rm o2sim_grp.root
rm MCStepLoggerVolMap.dat
rm o2sim_proc-cut.dat
rm MCStepLoggerSenVol.dat
rm gphysi.dat
rm run_stratrack.sh
rm config_custom_Pythia.cfg
rm configPythia.ini
rm generator_pythia8_gun.C
rm RecoDecay.h
rm pp13.cmnd
rm run_strangenesstracking_01.C
rm pp13.cmnd
rm trigger_multiplicity.C
rm histooutput.root
mv treeoutput.root ${outdir}
echo "Anything left?" 
ls
echo "Done! Enjoy!"
