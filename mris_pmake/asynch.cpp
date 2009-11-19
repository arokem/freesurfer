/***************************************************************************
 *   Copyright (C) 2004 by Rudolph Pienaar / Christian Haselgrove          *
 *   {ch|rudolph}@nmr.mgh.harvard.edu                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
// $Id: asynch.cpp,v 1.5 2009/11/19 21:15:20 rudolph Exp $

#include <string>
#include <sstream>

#include "asynch.h"
#include "C_mpmProg.h"
#include "c_vertex.h"
#include "c_label.h"
#include "c_surface.h"

bool
asynchEvent_processWGHT(
  s_env&    ast_env,
  string    astr_comms
) {

  int lw     = ast_env.lw;
  int rw     = ast_env.rw;

  string str_errorAct = "checking <WGHT>";

  string str_object = "";
  string str_verb = "";
  string str_modifier = "";
  string str_sep  = " ";
  float f_val  = 0.0;

  std::_Ios_Fmtflags origFlags;
  origFlags  = cout.flags();
  cout.setf(ios::left);

  if (!str_3parse( astr_comms, str_object, str_verb, str_modifier))
    warn(str_errorAct, "Some error occurred in the 3parse.", 1);

  if (str_object == "all") {
    if (str_verb == "get") {
      s_weights_print(*ast_env.pSTw);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      s_weights_setAll(*ast_env.pSTw, f_val);
    }
  }
  if (str_object == "wd") {
    if (str_verb == "get") {
      CW(lw, "wd");
      CWn(rw, ast_env.pSTw->wd);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTw->wd =  f_val;
    }
  }
  if (str_object == "wc") {
    if (str_verb == "get") {
      CW(lw, "wc");
      CWn(rw, ast_env.pSTw->wc);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTw->wc =  f_val;
    }
  }
  if (str_object == "wh") {
    if (str_verb == "get") {
      CW(lw, "wh");
      CWn(rw, ast_env.pSTw->wh);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTw->wh =  f_val;
    }
  }
  if (str_object == "wdc") {
    if (str_verb == "get") {
      CW(lw, "wdc");
      CWn(rw, ast_env.pSTw->wdc);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTw->wdc =  f_val;
    }
  }
  if (str_object == "wdh") {
    if (str_verb == "get") {
      CW(lw, "wdh");
      CWn(rw, ast_env.pSTw->wdh);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTw->wdh =  f_val;
    }
  }
  if (str_object == "wch") {
    if (str_verb == "get") {
      CW(lw, "wch");
      CWn(rw, ast_env.pSTw->wch);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTw->wch =  f_val;
    }
  }
  if (str_object == "wdch") {
    if (str_verb == "get") {
      CW(lw, "wdch");
      CWn(rw, ast_env.pSTw->wdch);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTw->wdch =  f_val;
    }
  }
  if (str_object == "wdir") {
    if (str_verb == "get") {
      CW(lw, "wdir");
      CWn(rw, ast_env.pSTw->wdir);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTw->wdir =  f_val;
    }
  }

  cout.flags(origFlags);
  return true;
}

bool
asynchEvent_processDWGHT(
  s_env&    ast_env,
  string    astr_comms
) {

  int lw     = ast_env.lw;
  int rw     = ast_env.rw;

  string str_errorAct = "checking <DWGHT>";

  string str_object = "";
  string str_verb = "";
  string str_modifier = "";
  string str_sep  = " ";
  float f_val  = 0.0;

  std::_Ios_Fmtflags origFlags;
  origFlags  = cout.flags();
  cout.setf(ios::left);

  if (!str_3parse( astr_comms, str_object, str_verb, str_modifier))
    warn(str_errorAct, "Some error occurred in the 3parse.", 1);

  if (str_object == "all") {
    if (str_verb == "get") {
      s_Dweights_print(*ast_env.pSTDw);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      s_Dweights_setAll(*ast_env.pSTDw, f_val);
    }
  }
  if (str_object == "Dwd") {
    if (str_verb == "get") {
      CW(lw, "Dwd");
      CWn(rw, ast_env.pSTDw->Dwd);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTDw->Dwd =  f_val;
    }
  }
  if (str_object == "Dwc") {
    if (str_verb == "get") {
      CW(lw, "Dwc");
      CWn(rw, ast_env.pSTDw->Dwc);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTDw->Dwc =  f_val;
    }
  }
  if (str_object == "Dwh") {
    if (str_verb == "get") {
      CW(lw, "Dwh");
      CWn(rw, ast_env.pSTDw->Dwh);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTDw->Dwh =  f_val;
    }
  }
  if (str_object == "Dwdc") {
    if (str_verb == "get") {
      CW(lw, "Dwdc");
      CWn(rw, ast_env.pSTDw->Dwdc);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTDw->Dwdc =  f_val;
    }
  }
  if (str_object == "Dwdh") {
    if (str_verb == "get") {
      CW(lw, "Dwdh");
      CWn(rw, ast_env.pSTDw->Dwdh);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTDw->Dwdh =  f_val;
    }
  }
  if (str_object == "Dwch") {
    if (str_verb == "get") {
      CW(lw, "Dwch");
      CWn(rw, ast_env.pSTDw->Dwch);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTDw->Dwch =  f_val;
    }
  }
  if (str_object == "Dwdch") {
    if (str_verb == "get") {
      CW(lw, "Dwdch");
      CWn(rw, ast_env.pSTDw->Dwdch);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTDw->Dwdch =  f_val;
    }
  }
  if (str_object == "Dwdir") {
    if (str_verb == "get") {
      CW(lw, "Dwdir");
      CWn(rw, ast_env.pSTDw->Dwdir);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      f_val = atof(str_modifier.c_str());
      ast_env.pSTDw->Dwdir =  f_val;
    }
  }

  cout.flags(origFlags);
  return true;
}

bool
asynchEvent_processVERTEX(
  s_env&    st_env,
  string    astr_comms
) {

  int lw     = st_env.lw;
  int rw     = st_env.rw;

  string str_errorAct = "checking <VERTEX>";

  string  str_object = "";
  string  str_verb = "";
  string  str_modifier = "";
  string  str_sep  = " ";
  int   val  = 0;
  stringstream Gsout("");

  std::_Ios_Fmtflags origFlags;
  origFlags  = cout.flags();
  cout.setf(ios::left);

  if (!str_3parse( astr_comms, str_object, str_verb, str_modifier))
    warn(str_errorAct, "Some error occurred in the 3parse.", 1);

  if (str_object == "start") {
    if (str_verb == "get") {
      CW(lw, "start vertex");
      CWn(rw, st_env.startVertex);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      val = atoi(str_modifier.c_str());
      Gsout.str("");
      Gsout << "Setting VERTEX start to \t\t\t\t\t[ " << val << " ]" << endl;
      st_env.startVertex =  val;
      ULOUT(Gsout.str());
    }
  }
  if (str_object == "end") {
    if (str_verb == "get") {
      CW(lw, "end vertex");
      CWn(rw, st_env.endVertex);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      val = atoi(str_modifier.c_str());
      Gsout.str("");
      Gsout << "Setting VERTEX end to \t\t\t\t\t\t[ " << val << " ]" << endl;
      st_env.endVertex =  val;
      ULOUT(Gsout.str());
    }
  }
  cout.flags(origFlags);
  return true;
}

bool
asynchEvent_processENV(
  s_env&    st_env,
  string    astr_comms
) {

  int lw     = st_env.lw;
  int rw     = st_env.rw;

  string str_errorAct = "checking <ENV>";

  string  str_object    = "";
  string  str_verb      = "";
  string  str_modifier  = "";
  string  str_sep       = " ";
  int     val           = 0;
  stringstream Gsout("");

  std::_Ios_Fmtflags origFlags;
  origFlags  = cout.flags();
  cout.setf(ios::left);

  if (!str_3parse( astr_comms, str_object, str_verb, str_modifier))
    warn(str_errorAct, "Some error occurred in the 3parse.", 1);

  if (str_object == "mpmProg") {
    if (str_verb == "use")
        st_env.b_mpmProgUse     = true;
    if (str_verb == "get")
        s_env_mpmProgList(st_env);
    else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting mpmProgIndex to \t\t\t\t\t[ " << str_modifier << " ]" << endl;
      if (s_env_mpmProgSetIndex(&st_env, atoi(str_modifier.c_str())) == -1)
        error_exit("setting mpmProgIndex", "Some error occurred", 1);
      ULOUT(Gsout.str());
    }
  }

  if (str_object == "surfaceFile") {
    if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting surfaceFile to \t\t\t\t\t\t[ " << str_modifier << " ]" << endl;
      if (!s_env_surfaceFile_set(st_env, str_modifier))
        error_exit("Setting surfaceFile", "Some error occurred", 1);
      ULOUT(Gsout.str());
    }
  }
  if (str_object == "surfaceCurvature") {
    if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting surfaceCurvature to \t\t\t\t\t[ " << str_modifier << " ]" << endl;
      if (!s_env_surfaceCurvature_set(st_env, str_modifier))
        error_exit("Setting surfaceCurvature", "Some error occurred", 1);
      ULOUT(Gsout.str());
    }
  }
  if (str_object == "surfaceSulcal") {
    if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting surfaceSulcal to \t\t\t\t\t[ " << str_modifier << " ]" << endl;
      if (!s_env_surfaceSulcal_set(st_env, str_modifier))
        error_exit("Setting surfaceSulcal", "Some error occurred", 1);
      ULOUT(Gsout.str());
    }
  }

  if (str_object == "auxSurfaceFile") {
    if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting auxSurfaceFile to \t\t\t\t\t[ " << str_modifier << " ]" << endl;
      if (!s_env_auxSurfaceFile_set(st_env, str_modifier))
        error_exit("Setting auxSurfaceFile", "Some error occurred", 1);
      ULOUT(Gsout.str());
    }
  }
  if (str_object == "auxSurfaceCurvature") {
    if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting auxSurfaceCurvature to \t\t\t\t\t[ " << str_modifier << " ]" << endl;
      if (!s_env_auxSurfaceCurvature_set(st_env, str_modifier))
        error_exit("Setting auxSurfaceCurvature", "Some error occurred", 1);
      ULOUT(Gsout.str());
    }
  }

  if (str_object == "costFunctionIndex") {
    if (str_verb == "get")
        s_env_costFctList(st_env);
    else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting costFunctionIndex to \t\t\t\t\t[ " << str_modifier << " ]" << endl;
      if (s_env_costFctSetIndex(&st_env, atoi(str_modifier.c_str())) == -1)
        error_exit("setting costFunctionIndex", "Some error occurred", 1);
      ULOUT(Gsout.str());
    }
  }

  if (str_object == "syslog") {
    if (str_verb == "get") {
      CW(lw, "syslog");
      CWn(rw, st_env.pcsm_syslog->str_filename_get());
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting syslog to \t\t\t\t\t\t[ " << str_modifier << " ]" << endl;
      s_env_log_file_changeTo(st_env, e_sys, str_modifier);
      ULOUT(Gsout.str());
    }
  }
  if (str_object == "userlog") {
    if (str_verb == "get") {
      CW(lw, "userlog");
      CWn(rw, st_env.pcsm_userlog->str_filename_get());
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting userlog to \t\t\t\t\t\t[ " << str_modifier << " ]" << endl;
      s_env_log_file_changeTo(st_env, e_user, str_modifier);
      ULOUT(Gsout.str());
    }
  }
  if (str_object == "resultlog") {
    if (str_verb == "get") {
      CW(lw, "resultlog");
      CWn(rw, st_env.pcsm_resultlog->str_filename_get());
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting resultlog to \t\t\t\t\t\t[ " << str_modifier << " ]" << endl;
      s_env_log_file_changeTo(st_env, e_result, str_modifier);
      ULOUT(Gsout.str());
    }
  }
  if (str_object == "surfacesSync") {
    if (str_verb == "get") {
      CW(lw, "surfacesSync");
      CWn(rw, st_env.b_surfacesKeepInSync);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      val = atoi(str_modifier.c_str());
      Gsout.str("");
      Gsout << "Setting surfacesSync to \t\t\t\t\t[ " << val << " ]" << endl;
      st_env.b_surfacesKeepInSync = val;
      ULOUT(Gsout.str());
    }
  }
  if (str_object == "surfacesClearFlag") {
    if (str_verb == "get") {
      CW(lw, "surfacesClearFlag");
      CWn(rw, st_env.b_surfacesClear);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      val = atoi(str_modifier.c_str());
      Gsout.str("");
      Gsout << "Setting surfacesClearFlag to \t\t\t\t\t[ " << val << " ]" << endl;
      st_env.b_surfacesClear = val;
      ULOUT(Gsout.str());
    }
  }
  if (str_object == "sleep") {
    if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      val = atoi(str_modifier.c_str());
      Gsout.str("");
      Gsout << "Slept for \t\t\t\t\t\t\t[ " << val << " ]" << endl;
      sleep(val);
      ULOUT(Gsout.str());
    }
  }

  cout.flags(origFlags);
  return true;
}

bool
asynchEvent_processMPMPROG(
    s_env&      st_env,
    string      astr_comms
) {

  int lw     = st_env.lw;
  int rw     = st_env.rw;

  string str_errorAct = "checking <MPMPROG>";

  string  str_object    = "";
  string  str_verb      = "";
  string  str_modifier  = "";
  string  str_sep       = " ";
  int     val           = 0;
  stringstream Gsout("");

  std::_Ios_Fmtflags origFlags;
  origFlags  = cout.flags();
  cout.setf(ios::left);

  if (!str_3parse( astr_comms, str_object, str_verb, str_modifier))
    warn(str_errorAct, "Some error occurred in the 3parse.", 1);

  if (str_object == "polar") {
    C_mpmProg*          pC_mpmEnv = st_env.pCmpmProg;
    C_mpmProg_autodijk* pC_mpm_autodijk;
    pC_mpm_autodijk     = dynamic_cast<C_mpmProg_autodijk*>(pC_mpmEnv);
    if (str_verb == "get") {
        CW(lw, "Polar vertex:")
        val             = pC_mpm_autodijk->vertexPolar_get();
        CWn(rw, val);
    }
    else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      Gsout << "Setting polar vertex to \t\t\t\t\t[ " << str_modifier;
      Gsout << " ]" << endl;
      pC_mpm_autodijk->vertexPolar_set(atoi(str_modifier.c_str()));
      ULOUT(Gsout.str());
    }
  }
  cout.flags(origFlags);
  return true;
}

bool
asynchEvent_processLABEL(
  s_env&    st_env,
  string    astr_comms
) {

  int lw     = st_env.lw;
  int rw     = st_env.rw;

  string str_errorAct  = "checking <LABEL>";

  string  str_object = "";
  string  str_verb = "";
  string  str_modifier = "";
  string  str_sep  = " ";
  int   val  = 0;
  void*  pv_void = NULL;
  stringstream Gsout("");

  std::_Ios_Fmtflags origFlags;
  origFlags  = cout.flags();
  cout.setf(ios::left);

  if (!str_3parse( astr_comms, str_object, str_verb, str_modifier))
    warn(str_errorAct, "Some error occurred in the 3parse.", 1);

  if (str_verb == "singleVertexSet") {
    char    ch_mark  = TRUE;
    char*   pch_mark = &ch_mark;
    void*   pv_mark  = (void*) pch_mark;
    if (!str_modifier.length())
      return false;
    int vertex  = atoi(str_modifier.c_str());
    if (str_object          == "workingSurface") {
      label_singleVertexSet(st_env.pMS_curvature, vertex,
                            vertex_ripFlagMark, pv_mark);
    } else if (str_object   == "auxSurface") {
      label_singleVertexSet(st_env.pMS_auxSurface, vertex,
                            vertex_ripFlagMark, pv_mark);
    } else if (str_object   == "activeSurface") {
      label_singleVertexSet(st_env.pMS_active, vertex,
                            vertex_ripFlagMark, pv_mark);
    } else
      return false;
  }

  if (str_verb == "loadFrom") {
    char ch_mark   = TRUE;
    char* pch_mark  = &ch_mark;
    void* pv_mark   = (void*) pch_mark;
    string str_fileSpec = str_modifier;
    if (!str_modifier.length())
      return false;
    if (relDirSpec_test(str_modifier))
      str_fileSpec = st_env.str_workingDir + str_modifier;
    if (str_object          == "workingSurface") {
      label_coreLoad(st_env.pMS_curvature, str_fileSpec,
                     vertex_ripFlagMark, pv_mark);
    } else if (str_object   == "auxSurface") {
      label_coreLoad(st_env.pMS_auxSurface, str_fileSpec,
                     vertex_ripFlagMark, pv_mark);
    } else if (str_object   == "activeSurface") {
      label_coreLoad(st_env.pMS_active, str_fileSpec,
                     vertex_ripFlagMark, pv_mark);
    } else
      return false;
  }

  if (str_verb == "SaveTo") {
    string str_fileSpec = str_modifier;
    if (!str_modifier.length())
      return false;
    if (relDirSpec_test(str_modifier))
      str_fileSpec = st_env.str_workingDir + str_modifier;
    if (str_object          == "workingSurface") {
      label_coreSave(st_env.pMS_curvature, str_fileSpec,
                     vertex_ripFlagIsTrue, pv_void);
    } else if (str_object   == "auxSurface") {
      label_coreSave(st_env.pMS_auxSurface, str_fileSpec,
                     vertex_ripFlagIsTrue, pv_void);
    } else if (str_object   == "activeSurface") {
      label_coreSave(st_env.pMS_active, str_fileSpec,
                     vertex_ripFlagIsTrue, pv_void);
    } else
      return false;
  }

  if (str_object == "terminals") {
    if (str_verb == "findIn") {
      if (!str_modifier.length())
        return false;
      ULOUT("Searching for terminal vertices");
      string  str_fileName   = str_modifier;
      bool b_terminalsFound = false;
      deque<int> que_terminal;
      b_terminalsFound = label_terminalsFind(st_env.pMS_curvature,
                                             str_fileName, que_terminal);
      if (!b_terminalsFound) {
        nULOUT("\t\t\t\t\t[ none found ]\n");
      } else {
        nULOUT("\t\t\t\t\t[ done ]\n");
        for (unsigned i=0; i<que_terminal.size(); i++) {
          Gsout.str("");
          Gsout << "Terminal " << i << "\t\t\t\t\t\t\t[ ";
          Gsout << que_terminal[i] << " ]" << endl;
          ULOUT(Gsout.str());
          if (i>2) {
            ULOUT("Warning! High terminal number detected!\n");
          }
        }
      }
    }
  }

  if (str_object == "ply") {
    if (str_verb == "get") {
      CW(lw, "ply depth");
      CWn(rw, st_env.plyDepth);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      val = atoi(str_modifier.c_str());
      Gsout << "Setting ply depth to \t\t\t\t\t\t[ " << val << " ]" << endl;
      st_env.plyDepth =  val;
      ULOUT(Gsout.str());
    } else if (str_verb == "do") {
      ULOUT("Performing ply search");
      label_ply_do(st_env);
      nULOUT("\t\t\t\t\t\t[ ok ]\n");
    } else if (str_verb == "saveStaggered") {
      bool b_staggered = true;
      if (!str_modifier.length())
        return false;
      ULOUT("Saving ply label files...\n");
      label_ply_save(st_env, str_modifier, b_staggered);
    } else if (str_verb == "save") {
      bool b_staggered = false;
      if (!str_modifier.length())
        return false;
      ULOUT("Saving ply label files...\n");
      label_ply_save(st_env, str_modifier, b_staggered);
    } else if (str_verb == "functionList") {
      s_env_costFctList(st_env);
    } else if (str_verb == "functionAssign") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      val = atoi(str_modifier.c_str());
      Gsout << "Setting ply function to \t\t\t\t\t[ " << val << " ]" << endl;
      ULOUT(Gsout.str());
      s_env_costFctSetIndex(&st_env, val);
    }
  }
  cout.flags(origFlags);
  return true;
}

bool
asynchEvent_processSURFACE(
  s_env&    st_env,
  string    astr_comms
) {

  string  str_errorAct = "checking <SURFACE>";

  string  str_object = "";
  string  str_verb = "";
  string  str_modifier = "";
  string  str_sep  = " ";
  int   val  = 0;

  stringstream Gsout("");


  std::_Ios_Fmtflags origFlags;
  origFlags  = cout.flags();
  cout.setf(ios::left);

  if (!str_3parse( astr_comms, str_object, str_verb, str_modifier))
    warn(str_errorAct, "Some error occurred in the 3parse.", 1);

  if (str_object == "active") {
    if (str_verb == "get") {
      s_env_activeSurfaceList(st_env);
    } else if (str_verb == "set") {
      if (!str_modifier.length())
        return false;
      Gsout.str("");
      val = atoi(str_modifier.c_str());
      Gsout << "Setting active surface to \t\t\t\t\t[ " << val << " ]" << endl;
      ULOUT(Gsout.str());
      s_env_activeSurfaceSetIndex(&st_env, val);
    } else if (str_verb == "ripClear") {
      bool b_wholeSurface = true;
      surface_ripClear(st_env, b_wholeSurface);
    }
  }

  if (str_object == "signumFunction") {
    if (str_verb == "do") {
      Gsout.str("");
      Gsout << "Performing surface signumFunction\t\t\t\t";
      surface_signumFunction_do(st_env);
      Gsout << "[ ok ]\n";
      ULOUT(Gsout.str());
    }
  }

  if (str_object == "correlationFunction") {
    if (str_verb == "do") {
      Gsout.str("");
      Gsout << "Performing surface correlationFunction\t\t\t\t";
      surface_correlationFunction_do(st_env);
      Gsout << "[ ok ]\n";
      ULOUT(Gsout.str());
    }
  }

  if (str_object == "rawCurveSum") {
    if (str_verb == "do") {
      Gsout.str("");
      Gsout << "Performing rawCurveSum function\t\t\t\t\t";
      surface_rawCurveSum_do(st_env);
      Gsout << "[ ok ]\n";
      ULOUT(Gsout.str());
    }
  }

  if (str_object == "rawCurveMinMax") {
    if (str_verb == "do") {
      Gsout.str("");
      Gsout << "Performing rawCurveMinMax function\t\t\t\t\t";
      surface_rawCurveMinMax_do(st_env);
      Gsout << "[ ok ]\n";
      ULOUT(Gsout.str());
    }
  }

  if (str_object == "annotation") {
    if (str_verb == "do") {
      Gsout.str("");
      Gsout << "Performing annotation function\t\t\t\t\t";
      surface_annotation_do(st_env);
      Gsout << "[ ok ]\n";
      ULOUT(Gsout.str());
    }
  }

  if (str_object == "averageIntegratedCurveArea") {
    if (str_verb == "do") {
      e_CURVATURE  e_curvature;
      if (!str_modifier.length())
        e_curvature = e_gaussian;
      Gsout.str("");
      val = atoi(str_modifier.c_str());
      e_curvature  = (e_CURVATURE) val;
      Gsout << "Setting curvature type to \t\t\t\t\t[ " << val << " ]" << endl;
      ULOUT(Gsout.str());
      Gsout.str("");
      Gsout << "Performing surface averageIntegratedCurveArea\t\t\t";
      surface_averageIntegratedCurveArea_do(st_env, e_curvature);
      Gsout << "[ ok ]\n";
      ULOUT(Gsout.str());
    }
  }

  cout.flags(origFlags);
  return true;
}

void
asynchEvent_process(
  s_env&    st_env,
  string    str_event
) {
  //
  // ARGS
  // st_env    in  process environment
  // str_event   in  event string
  //
  // DESCRIPTION
  // Processes a string <str_event> that was received on the process
  // server socket.
  //
  // Since some events might modify the process environment, a st_env
  // structure reference is also passed.
  //
  // This function really only changes the internal state of several
  // program variables, in preparation for a subsequent event processing
  // loop.
  //
  // PRECONDITIONS
  // o None.
  //
  // POSTCONDITIONS
  // o No checking is done on event syntax or semantics!
  //
  // HISTORY
  // 09 December 2004
  // o Initial design and coding.
  //
  // 11 January 2005
  // o Added {USER,SYS}ECHO
  //

  //debug_push("asynchEvent_process");
  unsigned      pos             = 0;
  string        str_path        = "";
  string        str_optionsFile = "";
  string        str_optionsArg  = "";
  string        str_text        = "";

  stringstream Gsout("");


  // Check for SYSECHO
  pos = str_event.find("SYSECHO");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 8)
        warn("checking <SYSECHO>", "no argument was found.", 2);
    else {
        str_text  = str_event.substr(pos+8);
        Gsout.str("");
        Gsout << "ECHO: " << str_text << endl;
        SLOUT(Gsout.str());
    }    
  }

  // Check for USERECHO
  pos = str_event.find("USERECHO");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 9)
      warn("checking <USERECHO>", "no argument was found.", 2);
    else {
        str_text  = str_event.substr(pos+9);
        Gsout.str("");
        Gsout << "ECHO: " << str_text << endl;
        ULOUT(Gsout.str());
    }
  }

  // Check for RESULTECHO
  pos = str_event.find("RESULTECHO");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 11)
      warn("checking <RESULTECHO>", "no argument was found.", 2);
    else {
        str_text  = str_event.substr(pos+11);
        Gsout.str("");
        Gsout << "ECHO: " << str_text << endl;
        RLOUT(Gsout.str());
    }
  }

  // Check for OPT
  pos = str_event.find("OPT");
  if (pos != (unsigned)string::npos) {
    string str_pathAbs;
    if (str_event.length() < 4)
      warn("checking <OPT>", "no argument was found.", 2);
    else {
        str_optionsArg = str_event.substr(pos+4);

        pos = str_optionsArg.rfind("/");
        str_path  = (pos == (unsigned)string::npos) ?
                    "./" :
                    str_optionsArg.substr(0, pos);
        str_optionsFile = (pos == (unsigned)string::npos) ?
                        str_optionsArg :
                        str_optionsArg.substr(pos+1);

        str_pathAbs  = str_path;
        str_rel2absDirSpec_change(str_path, str_pathAbs);
        st_env.str_workingDir  = str_pathAbs + "/";
        st_env.str_optionsFileName = str_optionsFile;
        Gsout.str("");
        Gsout << "PATH: " << st_env.str_workingDir << endl;
        SLOUT(Gsout.str());
        Gsout.str("");
        Gsout << "OptionsFile: " << st_env.str_optionsFileName << endl;
        SLOUT(Gsout.str());
    }
  }

  // Check for CWD
  pos = str_event.find("CWD");
  if (pos != (unsigned)string::npos) {
    string str_pathAbs;
    if (str_event.length() < 4)
      warn("checking <CWD>", "no argument was found.", 2);
    else {
        str_path  = str_event.substr(pos+4);
        str_pathAbs  = str_path;
        str_rel2absDirSpec_change(str_path, str_pathAbs);
        st_env.str_workingDir = str_pathAbs + "/";
        Gsout.str("");
        Gsout << "PATH: " << st_env.str_workingDir << endl;
        SLOUT(Gsout.str());
    }
  }

  // Check for HELP
  pos = str_event.find("HELP");
  if (pos != (unsigned)string::npos) {
    // Now remove the HELP<sp> string
    str_event.erase(0, 5);
    asynchEvent_processHELP(st_env, str_event);
  }

  // Check for ENV
  pos = str_event.find("ENV");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 4)
        warn("checking <ENV>", "no argument was found.", 2);
    else {
        // Now remove the ENV<sp> string
        str_event.erase(0, 4);
        asynchEvent_processENV(st_env, str_event);
    }
  }

  // Check for MPMPROG
  pos = str_event.find("MPMPROG");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 4)
        warn("checking <MPMPROG>", "no argument was found.", 2);
    else {
        // Now remove the MPMPROG<sp> string
        str_event.erase(0, 8);
        asynchEvent_processMPMPROG(st_env, str_event);
    }
  }

  // Check for DWGHT
  pos = str_event.find("DWGHT");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 6)
      warn("checking <DWGHT>", "no argument was found.", 2);
    else {
        // Now remove the DWGHT<sp> string
        str_event.erase(0, 6);
        asynchEvent_processDWGHT(st_env, str_event);
    }
  }

  // Check for WGHT
  pos = str_event.find("WGHT");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 5)
      warn("checking <WGHT>", "no argument was found.", 2);
    else {
        // Now remove the WGHT<sp> string
        str_event.erase(0, 5);
        asynchEvent_processWGHT(st_env, str_event);
    }
  }

  // Check for VERTEX
  pos = str_event.find("VERTEX");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 7)
      warn("checking <VERTEX>", "no argument was found.", 2);
    else {
        // Now remove the VERTEX<sp> string
        str_event.erase(0, 7);
        asynchEvent_processVERTEX(st_env, str_event);
    }
  }

  // Check for LABEL
  pos = str_event.find("LABEL");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 6)
      warn("checking <LABEL>", "no argument was found.", 2);
    else {
        // Now remove the VERTEX<sp> string
        str_event.erase(0, 6);
        asynchEvent_processLABEL(st_env, str_event);
    }
  }

  // Check for SURFACE
  pos = str_event.find("SURFACE");
  if (pos != (unsigned)string::npos) {
    if (str_event.length() < 7)
      warn("checking <SURFACE>", "no argument was found.", 2);
    else {
        // Now remove the VERTEX<sp> string
        str_event.erase(0, 8);
        asynchEvent_processSURFACE(st_env, str_event);
    }
  }


  //debug_pop();
}

string
asynchEvent_poll(
    c_SSocket_UDP_receive*      pCSocketUDPR,
    int                         maxPolls
) {
    //
    // ARGS
    // pcSocketUDPR   in  socket on which to
    //        listen
    // maxPolls   in  maximum amount of
    //        polls before
    //        returning.
    //
    // DESCRIPTION
    // Listens on a given socket, and returns a string (received)
    // payload. This method polls the socket, so it will only return
    // if there is data.
    //
    // The amount of polls is controlled by <maxPolls>, which in a
    // time domain will wait for (timoutSec * maxPolls).
    //
    // HISTORY
    // 18 November 2004
    // o Initial design and coding.
    //

    int  i, rval;
    string str_payload = "TERM";

    if (!pCSocketUDPR)
        return str_payload;

    for (i=0; i<maxPolls; i++) {
        rval = pCSocketUDPR->recv(str_payload);
        if (rval > 0)
        break;
    }

    return str_payload;
}

/* eof */
