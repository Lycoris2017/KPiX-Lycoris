# KPiX-Lycoris

Desciption: DAQ software to read KPiX chip integrated to sensors of LYCORIS telescope. Original code in Copyright (c) 2011 by SLAC, All rights reserved.


# Short recipe for KPiX DAQ setup:
--------------

### Basic setup is:

#### Add the central KPiX-Daq repository to get the master branch:

```
git clone https://github.com/Lycoris2017/KPiX-Lycoris.git kpix_local
cd kpix_local
```

(Todo: add stable tags then document it for user/developper)

#### (Option) As developper:

If you are a developper of this software, please click the 'Fork' on top right of this page. Then add your mirror and push your 'dev' branch to it:

```
git remote add mykpix git@github.com:$YOUR_GITHUB_REPOSITORY/KPiX-Lycoris.git
git checkout -b local.dev
git commit -m "init commit, copy from central master branch"
git push -u mykpix local.dev
```

Collaboration ATTENTION! Please always push to your own branch, then to ask for a pull-request on the central git repository!

#### Compile

```
tcsh
source setup_env_template.csh
make -j 4
```

Make options:
* norm: no shared library libkpix.so produced
* share: only shared library libkpix.so produced (added to default option); Noted: pylibs is not included in this shared lib.

#### Branch descriptions:

* kpix.origin: all original codes from SLAC (may have some cusomitized output added, but no core functions shall changed)
* kpix.master: up-to-date latest development version, used for LYCORIS telescope at DESY-II.
