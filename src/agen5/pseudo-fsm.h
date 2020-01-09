/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (pseudo-fsm.h)
 *
 *  It has been AutoGen-ed  July 14, 2013 at 05:37:27 PM by AutoGen 5.18
 *  From the definitions    pseudo.def
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
/*
 *  This file enumerates the states and transition events for a FSM.
 *
 *  te_pm_state
 *      The available states.  FSS_INIT is always defined to be zero
 *      and FSS_INVALID and FSS_DONE are always made the last entries.
 *
 *  te_pm_event
 *      The transition events.  These enumerate the event values used
 *      to select the next state from the current state.
 *      PM_EV_INVALID is always defined at the end.
 */
#ifndef AUTOFSM_PSEUDO_FSM_H_GUARD
#define AUTOFSM_PSEUDO_FSM_H_GUARD 1
/**
 *  Finite State machine States
 *
 *  Count of non-terminal states.  The generated states INVALID and DONE
 *  are terminal, but INIT is not  :-).
 */
#define PM_STATE_CT  5
typedef enum {
    PM_ST_INIT,     PM_ST_ST_MARK,  PM_ST_AGEN,     PM_ST_TEMPL,
    PM_ST_END_MARK, PM_ST_INVALID,  PM_ST_DONE
} te_pm_state;

/**
 *  Finite State machine transition Events.
 *
 *  Count of the valid transition events
 */
#define PM_EVENT_CT 7
typedef enum {
    PM_EV_ED_MODE,    PM_EV_MARKER,     PM_EV_END_PSEUDO, PM_EV_AUTOGEN,
    PM_EV_TEMPLATE,   PM_EV_SUFFIX,     PM_EV_SCHEME,     PM_EV_INVALID
} te_pm_event;

/**
 *  Enumeration of the valid transition types
 *  Some transition types may be common to several transitions.
 */
typedef enum {
    PM_TR_INIT_MARKER,
    PM_TR_INVALID,
    PM_TR_NOOP,
    PM_TR_SKIP_ED_MODE,
    PM_TR_TEMPL_MARKER,
    PM_TR_TEMPL_SCHEME,
    PM_TR_TEMPL_SUFFIX
} te_pm_trans;
#define PM_TRANSITION_CT  7

/**
 *  State transition handling map.  Map the state enumeration and the event
 *  enumeration to the new state and the transition enumeration code (in that
 *  order).  It is indexed by first the current state and then the event code.
 */
typedef struct pm_transition t_pm_transition;
struct pm_transition {
    te_pm_state  next_state;
    te_pm_trans  transition;
};

#ifndef DEFINE_FSM
extern const t_pm_transition pm_trans_table[ PM_STATE_CT ][ PM_EVENT_CT ];

extern int
pm_invalid_transition( te_pm_state st, te_pm_event evt );
#else
const t_pm_transition
pm_trans_table[ PM_STATE_CT ][ PM_EVENT_CT ] = {

  /* STATE 0:  PM_ST_INIT */
  { { PM_ST_INIT, PM_TR_SKIP_ED_MODE },             /* EVT:  -*- */
    { PM_ST_ST_MARK, PM_TR_INIT_MARKER },           /* EVT:  MARKER */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  END_PSEUDO */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  AUTOGEN */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  TEMPLATE */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  SUFFIX */
    { PM_ST_INVALID, PM_TR_INVALID }                /* EVT:  SCHEME */
  },


  /* STATE 1:  PM_ST_ST_MARK */
  { { PM_ST_ST_MARK, PM_TR_SKIP_ED_MODE },          /* EVT:  -*- */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  MARKER */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  END_PSEUDO */
    { PM_ST_AGEN, PM_TR_NOOP },                     /* EVT:  AUTOGEN */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  TEMPLATE */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  SUFFIX */
    { PM_ST_INVALID, PM_TR_INVALID }                /* EVT:  SCHEME */
  },


  /* STATE 2:  PM_ST_AGEN */
  { { PM_ST_AGEN, PM_TR_SKIP_ED_MODE },             /* EVT:  -*- */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  MARKER */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  END_PSEUDO */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  AUTOGEN */
    { PM_ST_TEMPL, PM_TR_NOOP },                    /* EVT:  TEMPLATE */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  SUFFIX */
    { PM_ST_INVALID, PM_TR_INVALID }                /* EVT:  SCHEME */
  },


  /* STATE 3:  PM_ST_TEMPL */
  { { PM_ST_TEMPL, PM_TR_SKIP_ED_MODE },            /* EVT:  -*- */
    { PM_ST_END_MARK, PM_TR_TEMPL_MARKER },         /* EVT:  MARKER */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  END_PSEUDO */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  AUTOGEN */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  TEMPLATE */
    { PM_ST_TEMPL, PM_TR_TEMPL_SUFFIX },            /* EVT:  SUFFIX */
    { PM_ST_TEMPL, PM_TR_TEMPL_SCHEME }             /* EVT:  SCHEME */
  },


  /* STATE 4:  PM_ST_END_MARK */
  { { PM_ST_END_MARK, PM_TR_INVALID },              /* EVT:  -*- */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  MARKER */
    { PM_ST_DONE, PM_TR_NOOP },                     /* EVT:  END_PSEUDO */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  AUTOGEN */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  TEMPLATE */
    { PM_ST_INVALID, PM_TR_INVALID },               /* EVT:  SUFFIX */
    { PM_ST_INVALID, PM_TR_INVALID }                /* EVT:  SCHEME */
  }
};
#define PmFsmErr_off     19
#define PmEvInvalid_off  75
#define PmStInit_off     83


static char const zPmStrings[169] =
/*     0 */ "** OUT-OF-RANGE **\0"
/*    19 */ "FSM Error:  in state %d (%s), event %d (%s) is invalid\n\0"
/*    75 */ "invalid\0"
/*    83 */ "init\0"
/*    88 */ "st_mark\0"
/*    96 */ "agen\0"
/*   101 */ "templ\0"
/*   107 */ "end_mark\0"
/*   116 */ "-*-\0"
/*   120 */ "marker\0"
/*   127 */ "end_pseudo\0"
/*   138 */ "autogen\0"
/*   146 */ "template\0"
/*   155 */ "suffix\0"
/*   162 */ "scheme";

static const size_t aszPmStates[5] = {
    83,  88,  96,  101, 107 };

static const size_t aszPmEvents[8] = {
    116, 120, 127, 138, 146, 155, 162, 75 };


#define PM_EVT_NAME(t)   ( (((unsigned)(t)) >= 8) \
    ? zPmStrings : zPmStrings + aszPmEvents[t])

#define PM_STATE_NAME(s) ( (((unsigned)(s)) >= 5) \
    ? zPmStrings : zPmStrings + aszPmStates[s])

#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif

static int pm_invalid_transition( te_pm_state st, te_pm_event evt );

/* * * * * * * * * THE CODE STARTS HERE * * * * * * * */
/**
 *  Print out an invalid transition message and return EXIT_FAILURE
 */
static int
pm_invalid_transition( te_pm_state st, te_pm_event evt )
{
    /* START == INVALID TRANS MSG == DO NOT CHANGE THIS COMMENT */
    char const * fmt = zPmStrings + PmFsmErr_off;
    fprintf( stderr, fmt, st, PM_STATE_NAME(st), evt, PM_EVT_NAME(evt));
    /* END   == INVALID TRANS MSG == DO NOT CHANGE THIS COMMENT */

    return EXIT_FAILURE;
}

#endif /* DEFINE_FSM */

#endif /* AUTOFSM_PSEUDO_FSM_H_GUARD */
/*
 * Local Variables:
 * mode: C
 * c-file-style: "stroustrup"
 * indent-tabs-mode: nil
 * End:
 * end of pseudo-fsm.h */
