# GEC 2018 Tutorial [ARCHIVED]

This is the tutorial application originally developed for the Gaseous Electronics Conference (GEC)
2018 MOOSE Workshop (November 5-9, 2018).

As of September 28, 2022, this code has been updated to the current MOOSE standards and archived.
If interested in using MOOSE to simulate low-temperature plasma physics, please go to
https://github.com/shannon-lab/zapdos.

## Installation

Install [a conda environment for MOOSE](https://mooseframework.inl.gov/getting_started/installation/conda.html),
go to your preferred installation location and setup your conda environment in the following way:

```
conda deactivate
conda create -n gec_2018_tutorial moose-libmesh=2022.09.09=build_0 moose-tools=2022.07.18
conda activate gec_2018_tutorial
```

Then, clone and build this tutorial:

```
git clone https://github.com/shannon-lab/GEC-2018-moose-tutorial
cd GEC-2018-moose-tutorial
git submodule update --init moose
make -j4    # can replace "4" with the number of cores on your machine
```

Finally, run the tests to confirm everything is working as expected:

```
./run_tests -j4
```

**Note that** the `gec_workshop.pdf` file, while useful for following along with the steps, may be out
of date with respect to current MOOSE capability. Please always refer back to https://mooseframework.inl.gov
for more info on the current status of MOOSE.


