/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (defParse-fsm.c)
 *
 *  It has been AutoGen-ed  July 14, 2013 at 05:37:28 PM by AutoGen 5.18
 *  From the definitions    defParse.def
 *  and the template file   fsm
 *
 *  Automated Finite State Machine
 *
 *  Copyright (C) 1992-2013 Bruce Korb - all rights reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name ``Bruce Korb'' nor the name of any other
 *    contributor may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * AutoFSM IS PROVIDED BY Bruce Korb ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Bruce Korb OR ANY OTHER CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#define DEFINE_FSM
#include "defParse-fsm.h"
#include <stdio.h>

#define FSM_USER_HEADERS
#include "defParse.x"
#undef  FSM_USER_HEADERS

#ifndef NULL
#  define NULL 0
#endif

/**
 *  Callback routine prototype.  They return the next state.  Normally, that
 *  should be the value of the "maybe_next" argument.
 */
typedef te_dp_state (dp_callback_t)(
    te_dp_state initial,
    te_dp_state maybe_next,
    te_dp_event trans_evt );

static dp_callback_t
    dp_do_empty_val,
    dp_do_end_block,
    dp_do_have_name_lit_eq,
    dp_do_indexed_name,
    dp_do_invalid,
    dp_do_need_name_end,
    dp_do_need_name_var_name,
    dp_do_need_value_delete_ent,
    dp_do_next_val,
    dp_do_start_block,
    dp_do_str_value,
    dp_do_tpl_name;

/**
 *  Declare all the state transition handling routines.
 */
typedef struct transition t_dp_transition;
struct transition {
    te_dp_state      next_state;
    dp_callback_t*   trans_proc;
};

/**
 *  State transition maps.  Map the enumeration and the event enumeration
 *  to the new state and the transition enumeration code (in that order).
 *  It is indexed by first the current state and then the event code.
 */
static const t_dp_transition
dp_trans_table[ DP_STATE_CT ][ DP_EVENT_CT ] = {

  /* STATE 0:  DP_ST_INIT */
  { { DP_ST_NEED_DEF, NULL },                       /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  VAR_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  OTHER_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  NUMBER */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  ; */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  },

  /* STATE 1:  DP_ST_NEED_DEF */
  { { DP_ST_INVALID, dp_do_invalid },               /* EVT:  AUTOGEN */
    { DP_ST_NEED_TPL, NULL },                       /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  VAR_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  OTHER_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  NUMBER */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  ; */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  },

  /* STATE 2:  DP_ST_NEED_TPL */
  { { DP_ST_INVALID, dp_do_invalid },               /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_NEED_SEMI, dp_do_tpl_name },            /* EVT:  VAR_NAME */
    { DP_ST_NEED_SEMI, dp_do_tpl_name },            /* EVT:  OTHER_NAME */
    { DP_ST_NEED_SEMI, dp_do_tpl_name },            /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  NUMBER */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  ; */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  },

  /* STATE 3:  DP_ST_NEED_SEMI */
  { { DP_ST_INVALID, dp_do_invalid },               /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  VAR_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  OTHER_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  NUMBER */
    { DP_ST_NEED_NAME, NULL },                      /* EVT:  ; */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  },

  /* STATE 4:  DP_ST_NEED_NAME */
  { { DP_ST_NEED_DEF, NULL },                       /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_DONE, dp_do_need_name_end },            /* EVT:  End-Of-File */
    { DP_ST_HAVE_NAME, dp_do_need_name_var_name },  /* EVT:  VAR_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  OTHER_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  NUMBER */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  ; */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_HAVE_VALUE, dp_do_end_block },          /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  },

  /* STATE 5:  DP_ST_HAVE_NAME */
  { { DP_ST_INVALID, dp_do_invalid },               /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  VAR_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  OTHER_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  NUMBER */
    { DP_ST_NEED_NAME, dp_do_empty_val },           /* EVT:  ; */
    { DP_ST_NEED_VALUE, dp_do_have_name_lit_eq },   /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_NEED_IDX, NULL },                       /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  },

  /* STATE 6:  DP_ST_NEED_VALUE */
  { { DP_ST_INVALID, dp_do_invalid },               /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_HAVE_VALUE, dp_do_str_value },          /* EVT:  VAR_NAME */
    { DP_ST_HAVE_VALUE, dp_do_str_value },          /* EVT:  OTHER_NAME */
    { DP_ST_HAVE_VALUE, dp_do_str_value },          /* EVT:  STRING */
    { DP_ST_HAVE_VALUE, dp_do_str_value },          /* EVT:  HERE_STRING */
    { DP_ST_NEED_NAME, dp_do_need_value_delete_ent }, /* EVT:  DELETE_ENT */
    { DP_ST_HAVE_VALUE, dp_do_str_value },          /* EVT:  NUMBER */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  ; */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_NEED_NAME, dp_do_start_block },         /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  },

  /* STATE 7:  DP_ST_NEED_IDX */
  { { DP_ST_INVALID, dp_do_invalid },               /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_NEED_CBKT, dp_do_indexed_name },        /* EVT:  VAR_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  OTHER_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_NEED_CBKT, dp_do_indexed_name },        /* EVT:  NUMBER */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  ; */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  },

  /* STATE 8:  DP_ST_NEED_CBKT */
  { { DP_ST_INVALID, dp_do_invalid },               /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  VAR_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  OTHER_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  NUMBER */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  ; */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INDX_NAME, NULL }                       /* EVT:  ] */
  },

  /* STATE 9:  DP_ST_INDX_NAME */
  { { DP_ST_INVALID, dp_do_invalid },               /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  VAR_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  OTHER_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  NUMBER */
    { DP_ST_NEED_NAME, dp_do_empty_val },           /* EVT:  ; */
    { DP_ST_NEED_VALUE, NULL },                     /* EVT:  = */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  },

  /* STATE 10:  DP_ST_HAVE_VALUE */
  { { DP_ST_INVALID, dp_do_invalid },               /* EVT:  AUTOGEN */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DEFINITIONS */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  End-Of-File */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  VAR_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  OTHER_NAME */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  HERE_STRING */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  DELETE_ENT */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  NUMBER */
    { DP_ST_NEED_NAME, NULL },                      /* EVT:  ; */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  = */
    { DP_ST_NEED_VALUE, dp_do_next_val },           /* EVT:  , */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  { */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  } */
    { DP_ST_INVALID, dp_do_invalid },               /* EVT:  [ */
    { DP_ST_INVALID, dp_do_invalid }                /* EVT:  ] */
  }
};


#define DpFsmErr_off     19
#define DpEvInvalid_off  75
#define DpStInit_off     83


static char const zDpStrings[290] =
/*     0 */ "** OUT-OF-RANGE **\0"
/*    19 */ "FSM Error:  in state %d (%s), event %d (%s) is invalid\n\0"
/*    75 */ "invalid\0"
/*    83 */ "init\0"
/*    88 */ "need_def\0"
/*    97 */ "need_tpl\0"
/*   106 */ "need_semi\0"
/*   116 */ "need_name\0"
/*   126 */ "have_name\0"
/*   136 */ "need_value\0"
/*   147 */ "need_idx\0"
/*   156 */ "need_cbkt\0"
/*   166 */ "indx_name\0"
/*   176 */ "have_value\0"
/*   187 */ "autogen\0"
/*   195 */ "definitions\0"
/*   207 */ "End-Of-File\0"
/*   219 */ "var_name\0"
/*   228 */ "other_name\0"
/*   239 */ "string\0"
/*   246 */ "here_string\0"
/*   258 */ "delete_ent\0"
/*   269 */ "number\0"
/*   276 */ ";\0"
/*   278 */ "=\0"
/*   280 */ ",\0"
/*   282 */ "{\0"
/*   284 */ "}\0"
/*   286 */ "[\0"
/*   288 */ "]";

static const size_t aszDpStates[11] = {
    83,  88,  97,  106, 116, 126, 136, 147, 156, 166, 176 };

static const size_t aszDpEvents[17] = {
    187, 195, 207, 219, 228, 239, 246, 258, 269, 276, 278, 280, 282, 284, 286,
    288, 75 };


#define DP_EVT_NAME(t)   ( (((unsigned)(t)) >= 17) \
    ? zDpStrings : zDpStrings + aszDpEvents[t])

#define DP_STATE_NAME(s) ( (((unsigned)(s)) >= 11) \
    ? zDpStrings : zDpStrings + aszDpStates[s])

#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif

static int dp_invalid_transition( te_dp_state st, te_dp_event evt );

#define FSM_HANDLER_CODE
#include "defParse.x"
#undef  FSM_HANDLER_CODE

/**
 *  Run the FSM.  Will return DP_ST_DONE or DP_ST_INVALID
 */
te_dp_state
dp_run_fsm( void )
{
    te_dp_state dp_state = DP_ST_INIT;
    te_dp_event trans_evt;
    te_dp_state nxtSt;
    dp_callback_t* pT;

    while (dp_state < DP_ST_INVALID) {

#define FSM_FIND_TRANSITION
#include "defParse.x"
#undef  FSM_FIND_TRANSITION

#ifndef __COVERITY__
        if (trans_evt >= DP_EV_INVALID) {
            nxtSt = DP_ST_INVALID;
            pT    = dp_do_invalid;
        } else
#endif /* __COVERITY__ */
        {
            const t_dp_transition* pTT =
            dp_trans_table[ dp_state ] + trans_evt;
            nxtSt = pTT->next_state;
            pT    = pTT->trans_proc;
        }

        if (pT != NULL)
            nxtSt = (*pT)( dp_state, nxtSt, trans_evt );

        dp_state = nxtSt;
    }
    return dp_state;
}
/*
 * Local Variables:
 * mode: C
 * c-file-style: "stroustrup"
 * indent-tabs-mode: nil
 * End:
 * end of defParse-fsm.c */
