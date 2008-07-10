function Xfir = fast_st2fir(st,ntp,TR,psdwin,usew,use_v3)
% Xfir = fast_st2fir(st,ntp,TR,psdwin,<usew>,<use_v3>)
%
% Computes the FIR design matrix for the given schedule of one
% event type.
%
% st = [tonset duration <weight>]
% ntp = number of time points
% TR = time between time points
% psdwin = [psdmin psdmax dpsd];
% usew:  0, [], not spec = dont use weight, 1 = use weight
% use_v3 - make (more) consistent with version 3
%
% Notes:
%  1. Number of rows in st is the number of presentations.
%  2. Presenations may not overlap --
%     use different event types in this case.
%  3. Set your psdmax to be long enough for IRF and max duration
%  4. If st does not have weights, weights=1
%  5. Does not force dpsd to be an integer divisor of TR,
%     but it is a good idea.
%  6. If two stimuli fall within the sam TR bin, the Xfir
%     matrix will have a 2 instead of a 1.
% $Id: fast_st2fir.m,v 1.16 2008/07/10 21:00:09 greve Exp $


%
% fast_st2fir.m
%
% Original Author: Doug Greve
% CVS Revision Info:
%    $Author: greve $
%    $Date: 2008/07/10 21:00:09 $
%    $Revision: 1.16 $
%
% Copyright (C) 2002-2007,
% The General Hospital Corporation (Boston, MA). 
% All rights reserved.
%
% Distribution, usage and copying of this software is covered under the
% terms found in the License Agreement file named 'COPYING' found in the
% FreeSurfer source code root directory, and duplicated here:
% https://surfer.nmr.mgh.harvard.edu/fswiki/FreeSurferOpenSourceLicense
%
% General inquiries: freesurfer@nmr.mgh.harvard.edu
% Bug reports: analysis-bugs@nmr.mgh.harvard.edu
%

Xfir = [];
a = [];
Xfirss = [];

if(nargin < 4 | nargin > 6)
  fprintf('Xfir = fast_st2fir(st,ntp,TR,psdwin,<usew>,<use_v3>)\n');
  return;
end
if(~exist('usew','var')) usew = []; end
if(isempty(usew)) usew = 0; end
if(~exist('use_v3','var')) use_v3 = []; end
if(isempty(use_v3)) use_v3 = 0; end

psdmin  = psdwin(1);  % start of PSD window
psdmax  = psdwin(2);  % end of PSD window
dpsd    = psdwin(3);  % increment of PSD window
npsdwin = round((psdmax-psdmin)/dpsd);

% Empty st means that the condition is not present. This
% can only happen when the user has specified
% flac.AllowMissingCond. Return matrix of all 0s
if(isempty(st))
  Xfir = zeros(ntp,npsdwin);
  return;
end

nstim      = size(st,1);

% SubSampling
ssr = round(TR/dpsd); % Rate
nrows = ntp*ssr; % Number of rows after subsampling

% Presentation onset times
stimonset  = st(:,1); 

% Presentation duration - use dpsd if not specified
if(size(st,2) < 2)
  stimdur = dpsd*ones(nstim,1);
else
  stimdur = st(:,2); 
end

% Presentation weights - if not specified, set them to 1
if(size(st,2) < 3 | ~usew) 
  stimweight = ones(nstim,1);
else
  stimweight = st(:,3);
end

% The following two pieces of code prevent the case where stimuli
% of the same type are presented in a overlapping manner. It is,
% of course, ok to have the presentations of different stimulus
% types overlap (or even be simultaneous).
st = sortrows(st); % sort in order of onset time
d = diff(st(:,1));
ind = find(d == 0);
if(~isempty(ind))
  fprintf('ERROR: fast_st2fir: two or more presentations are simultaneous\n');
  return;
end

% Build the first teoplitz vector
a = zeros(nrows,1);
for nthstim = 1:nstim
  ionset = round((stimonset(nthstim)+psdmin)/dpsd) + 1; % start row
  if(ionset <= 0) continue; end
  if(ionset > nrows) continue; end
  ndur = round(stimdur(nthstim)/dpsd);
  ioffset = ionset+ndur-1; % end row
  if(ioffset > nrows) ioffset = nrows; end
  a(ionset:ioffset) = stimweight(nthstim);
end

% Build the second teoplitz vector
b = zeros(1,npsdwin);
b(1) = a(1);

% Construct the matrix
Xfirss = toeplitz(a,b);

% Subsample 
%Xfir = Xfirss(1:ssr:end,:);
if(ssr > 1)
  if(use_v3)
    Xfir = Xfirss(1:ssr:end,:);
  else
    tmp = reshape(Xfirss,[ssr ntp npsdwin]);
    Xfir = squeeze(sum(tmp));
  end
else
  Xfir = Xfirss;
end

return;
