# docker build for distributing a base fs 7.2.0 container

FROM centos:7

# shell settings
WORKDIR /root

# install utils
RUN yum -y update && yum -y install\
    bc \
    libgomp \
    perl \
    tar \
    tcsh \
    wget \
    vim-common \
    mesa-libGL \
    libXext \
    libSM \
    libXrender \
    libXmu \
    git \
    wget \
    tcsh \
    gcc \
    gcc-c++ \
    libgfortran-static \
    make \
    vim-common \
    lapack-devel \
    lapack-static \
    blas-devel \
    blas-static \
    zlib-devel \
    python-devel \
    python3-devel \
    libX11-devel \
    libXmu-devel \
    mesa-libGL-devel

RUN yum clean all
RUN wget https://download-ib01.fedoraproject.org/pub/epel/7/x86_64/Packages/g/git-annex-5.20140221-1.2.el7.x86_64.rpm && yum localinstall git-annex-5.20140221-1.2.el7.x86_64.rpm

# install fs
RUN git clone https://github.com/freesurfer/freesurfer.git && cd freesurfer && git remote add datasrc https://surfer.nmr.mgh.harvard.edu/pub/dist/freesurfer/repo/annex.git && git fetch datasrc && git-annex get . && wget https://surfer.nmr.mgh.harvard.edu/pub/data/fspackages/prebuilt/centos7-packages.tar.gz && tar -xzvf centos7-packages.tar.gz && cmake .  -DFS_PACKAGES_DIR="./"

# setup fs env
ENV OS Linux
ENV PATH /usr/local/freesurfer/bin:/usr/local/freesurfer/fsfast/bin:/usr/local/freesurfer/tktools:/usr/local/freesurfer/mni/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
ENV FREESURFER_HOME /usr/local/freesurfer
ENV FREESURFER /usr/local/freesurfer
ENV SUBJECTS_DIR /usr/local/freesurfer/subjects
ENV LOCAL_DIR /usr/local/freesurfer/local
ENV FSFAST_HOME /usr/local/freesurfer/fsfast
ENV FMRI_ANALYSIS_DIR /usr/local/freesurfer/fsfast
ENV FUNCTIONALS_DIR /usr/local/freesurfer/sessions

# set default fs options
ENV FS_OVERRIDE 0
ENV FIX_VERTEX_AREA ""
ENV FSF_OUTPUT_FORMAT nii.gz

# mni env requirements
ENV MINC_BIN_DIR /usr/local/freesurfer/mni/bin
ENV MINC_LIB_DIR /usr/local/freesurfer/mni/lib
ENV MNI_DIR /usr/local/freesurfer/mni
ENV MNI_DATAPATH /usr/local/freesurfer/mni/data
ENV MNI_PERL5LIB /usr/local/freesurfer/mni/share/perl5
ENV PERL5LIB /usr/local/freesurfer/mni/share/perl5
