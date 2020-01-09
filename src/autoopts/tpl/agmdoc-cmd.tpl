[+: -*- Mode: nroff -*-

  AutoGen5 template mdoc

## agman-cmd.tpl -- Template for command line mdoc pages
##
##  This file is part of AutoOpts, a companion to AutoGen.
##  AutoOpts is free software.
##  AutoOpts is Copyright (C) 1992-2013 by Bruce Korb - all rights reserved
##
##  AutoOpts is available under any one of two licenses.  The license
##  in use must be one of these two and the choice is under the control
##  of the user of the license.
##
##   The GNU Lesser General Public License, version 3 or later
##      See the files "COPYING.lgplv3" and "COPYING.gplv3"
##
##   The Modified Berkeley Software Distribution License
##      See the file "COPYING.mbsd"
##
##  These files have the following sha256 sums:
##
##  8584710e9b04216a394078dc156b781d0b47e1729104d666658aecef8ee32e95  COPYING.gplv3
##  4379e7444a0e2ce2b12dd6f5a52a27a4d02d39d247901d3285c88cf0d37f477b  COPYING.lgplv3
##  13aa749a5b0a454917a944ed8fffc530b784f5ead522b1aacaf4ec8aa55a6239  COPYING.mbsd

# Produce a man page for section 1, 5 or 8 commands.
# Which is selected via:  -DMAN_SECTION=n
# passed to the autogen invocation.  "n" may have a suffix, if desired.
#
:+][+:

(define head-line (lambda() (string-append
   ".Dd "   (shell "date '+%B %e %Y' | sed 's/  */ /g'")
   "\n.Dt " UP-PROG-NAME " " man-sect " " section-name
   "\n.Os " (shell "uname -sr") "\n") ))

(define man-page #f)

:+][+:

INCLUDE "cmd-doc.tlib"

:+]
.Sh NAME
.Nm [+: prog-name         :+]
.Nd [+: prog-title        :+]
[+: INVOKE build-doc      :+][+:

(out-move (string-append (get "prog-name") "."
          man-sect))      :+][+:#

.\" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
.\"  S Y N O P S I S
.\" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = :+][+:

DEFINE mk-synopsis                          :+][+:
  (out-push-new file-name)                 \:+]
.Sh SYNOPSIS
.Nm[+:

  IF (. use-flags)                          :+][+:
    IF (exist? "long-opts")                 :+]
.\" Mixture of short (flag) options and long options
.Op Fl flags
.Op Fl flag Ar value
.Op Fl \-option-name Ar value
[+: ELSE no long options:                   :+]
.Op Fl flags
.Op Fl flag Ar value
[+: ENDIF
                                            :+][+:
  ELIF (exist? "long-opts")
                                            :+]
.Op Fl \-option-name
.Op Fl \-option-name Ar value
[+:

  ELIF  (not (exist? "argument"))           :+]
.Op Ar option\-name Ar value
.Pp
All arguments are named options.
[+:
  ENDIF                                     :+][+:

  IF (exist? "argument")                    :+][+:
    argument                                :+][+:

    IF (exist? "reorder-args")              :+]
.Pp
Operands and options may be intermixed.  They will be reordered.
[+: ENDIF                                   :+][+:

  ELIF (or (exist? "long-opts") use-flags)

:+]
.Pp
All arguments must be options.
[+:

  ENDIF                                     :+][+:

  IF (exist? "main")                        :+][+:
  CASE main.main-type                       :+][+:
  == shell-process                          :+]
.Pp
This program will emit text that is expected to be evaluated by
a Bourne-compatible shell, thus digesting the options for the script.[+:

  == shell-parser                           :+]
.Pp
This program is designed to produce output suitable for inclusion
into a shell script that will parse the options described.[+:

  == for-each                               :+]
.Pp
The operands that this program operates on may be specified either
on the command line or read from standard input, one per line.
In that input, leading and trailing white space is stripped,
blank lines are ignored[+:

    IF (define comment-char (get "comment-char" "#"))
       (> (string-length comment-char) 1)  \:+]
 and lines beginning with the character
.I [+: (substring comment-char 1 0):+]
are treated as comments[+:
    ENDIF :+].[+:

    IF (exist? "interleaved")               :+]
Options may be interleaved with operands both on the command
line and when operands are read from standard input.[+:
    ENDIF  interleaved

:+]
Standard input may not be a terminal.[+:

  ESAC  main-type                           :+][+:
  ENDIF  main exists                        :+]
.Pp
[+:

FOR explain   "\n.Pp\n"                     :+][+:
  (get "explain" "")                        :+][+:
ENDFOR                                      :+][+:

(out-pop)                                   :+][+:

ENDDEF mk-synopsis

agmdoc-cmd.tpl ends here  :+]
