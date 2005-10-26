function [d, StartTime, TimeStep, ColIds] = tdr_ldgraddump(dfile)
% [d StartTime TimeStep ColIds] = tdr_ldgraddump(dfile)
% Loads a siemens gradient or RF dump file
% 
% d is either NxM
% N is the number of gradient samples
% M is the number of measures, which depends on who saved the data
%
% The measure names are stored in ColIds, and can be:
% adc: 0 = not sampling, 1 = sampling
%   xgrad   
%   ygrad   
%   zgrad   
%   xgradmom
%   ygradmom
%   zgradmom
%   rf (not with gradients and adc)
% The number of rows in ColIds must equal the number of cols in d
%
% Each row is a different post-excitation time
% First row starts at StartTime
% Each row increments time by TimeStep
%
% Note: one problem is that the gradient TimeStep is often
% twice that of the true ADC and RF, so there is some ambiguity
% as to where the gradients are during a sample.
% 
% See also: tdr_measasc.m
% 
% $Id: tdr_ldgraddump.m,v 1.1 2005/10/26 22:23:27 greve Exp $

%dfile = '/space/greve/1/users/greve/spiral/bay2-oct24/GradMom_spiral_32x32.txt';

if(nargin ~= 1)
  fprintf('[d StartTime TimeStep ColIds] = tdr_ldgraddump(dfile)\n');
  return;
end

fp = fopen(dfile,'r');
if(fp == -1)
  fprintf('ERROR: opening %s\n',dfile);
  return;
end

StartTime = [];
TimeStep  = [];
ColIds = '';

nthline = 1;
while(1)

  tline = fgetl(fp);
  if(tline == -1) break; end
  while(isempty(tline))
    tline = fgetl(fp);
  end

  %fprintf('%s\n',tline);
 
  if(tline(1) == ';') 
    %------- Read header info ---------------------%

    tmp = findstr('Start Time',tline);
    if(~isempty(tmp))
      item = sscanfitem(tline,5);
      if(isempty(item))
	fprintf('ERROR: reading Start Time in %s\n',dfile);
	fclose(fp);
	return;
      end
      StartTime = sscanf(item,'%f');
      fprintf('StartTime = %g\n',StartTime);
    end

    tmp = findstr('Time Step',tline);
    if(~isempty(tmp))
      item = sscanfitem(tline,5);
      if(isempty(item))
	fprintf('ERROR: reading Time Step in %s\n',dfile);
	fclose(fp);
	return;
      end
      TimeStep = sscanf(item,'%f');
      fprintf('TimeStep = %g\n',TimeStep);
    end

    tmp = findstr('ADC Signal Data',tline);
    if(~isempty(tmp)) ColIds = strvcat(ColIds,'adc'); end
  
    tmp = findstr('X Gradient',tline);
    if(~isempty(tmp)) ColIds = strvcat(ColIds,'xgrad'); end
  
    tmp = findstr('Y Gradient',tline);
    if(~isempty(tmp)) ColIds = strvcat(ColIds,'ygrad'); end
  
    tmp = findstr('Z Gradient',tline);
    if(~isempty(tmp)) ColIds = strvcat(ColIds,'zgrad'); end
  
    tmp = findstr('X-Gradientmoment',tline);
    if(~isempty(tmp)) ColIds = strvcat(ColIds,'xgradmom'); end
  
    tmp = findstr('Y-Gradientmoment',tline);
    if(~isempty(tmp)) ColIds = strvcat(ColIds,'ygradmom'); end
  
    tmp = findstr('Z-Gradientmoment',tline);
    if(~isempty(tmp)) ColIds = strvcat(ColIds,'zgradmom'); end
  
    tmp = findstr(' RF-Signal Data',tline);
    if(~isempty(tmp)) ColIds = strvcat(ColIds,'rf'); end
  
  else
    %----------------- Read the data -----------------------------
    % Read the first one to get the number of items
    vals = sscanf(tline,'%f')';
    fprintf('Loading\n');
    tic;
    d = fscanf(fp,'%f');
    fprintf('Done loading %g\n',toc);
    break;
  end

end % while

fclose(fp);

nvals = length(vals);
nd    = length(d);
if(rem(nd,nvals) ~= 0)
  fprintf('ERROR: reading vals %s\n',dfile);
  return;
end

d = reshape(d,[nvals nd/nvals])';      
d = [vals; d];

return;






