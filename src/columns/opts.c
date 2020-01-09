/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (opts.c)
 *
 *  It has been AutoGen-ed  July 14, 2013 at 05:37:32 PM by AutoGen 5.18
 *  From the definitions    opts.def
 *  and the template file   options
 *
 * Generated from AutoOpts 40:0:15 templates.
 *
 *  AutoOpts is a copyrighted work.  This source file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the columns author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The columns program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 1999-2012 Bruce Korb, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the GNU General Public License,
 *  version 3 or later <http://gnu.org/licenses/gpl.html>
 *
 *  columns is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  columns is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/** \file opts.c
 *  \addtogroup columns
 *  @{
 */

#ifndef __doxygen__
#define OPTION_CODE_COMPILE 1
#include "opts.h"
#include <sys/types.h>

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef  __cplusplus
extern "C" {
#endif
extern FILE * option_usage_fp;
#define zCopyright      (columns_opt_strs+0)
#define zLicenseDescrip (columns_opt_strs+268)

/*
 *  global included definitions
 */

#include <errno.h>

#define OPEN_ERROR_FMT      (columns_opt_strs+871)

#ifndef NULL
#  define NULL 0
#endif

/**
 *  static const strings for columns options
 */
static char const columns_opt_strs[2139] =
/*     0 */ "columns (GNU AutoGen) 1.2\n"
            "Copyright (C) 1999-2012 Bruce Korb, all rights reserved.\n"
            "This is free software. It is licensed for use, modification and\n"
            "redistribution under the terms of the GNU General Public License,\n"
            "version 3 or later <http://gnu.org/licenses/gpl.html>\n\0"
/*   268 */ "columns is free software: you can redistribute it and/or modify it under\n"
            "the terms of the GNU General Public License as published by the Free\n"
            "Software Foundation, either version 3 of the License, or (at your option)\n"
            "any later version.\n\n"
            "columns is distributed in the hope that it will be useful, but WITHOUT ANY\n"
            "WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS\n"
            "FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more\n"
            "details.\n\n"
            "You should have received a copy of the GNU General Public License along\n"
            "with this program.  If not, see <http://www.gnu.org/licenses/>.\n\0"
/*   871 */ "Error %d (%s) opening %s\n\0"
/*   897 */ "Specify the output dimensions:\0"
/*   928 */ "Maximum Line Width\0"
/*   947 */ "WIDTH\0"
/*   953 */ "width\0"
/*   959 */ "Desired number of columns\0"
/*   985 */ "COLUMNS\0"
/*   993 */ "columns\0"
/*  1001 */ "Set width of each column\0"
/*  1026 */ "COL_WIDTH\0"
/*  1036 */ "col-width\0"
/*  1046 */ "tab width\0"
/*  1056 */ "TAB_WIDTH\0"
/*  1066 */ "tab-width\0"
/*  1076 */ "Specify how to lay out the text:\0"
/*  1109 */ "maximum spread added to column width\0"
/*  1146 */ "SPREAD\0"
/*  1153 */ "spread\0"
/*  1160 */ "Fill lines with input\0"
/*  1182 */ "FILL\0"
/*  1187 */ "fill\0"
/*  1192 */ "Line prefix or indentation\0"
/*  1219 */ "INDENT\0"
/*  1226 */ "indent\0"
/*  1233 */ "First line prefix\0"
/*  1251 */ "FIRST_INDENT\0"
/*  1264 */ "first-indent\0"
/*  1277 */ "Formatting string for each input\0"
/*  1310 */ "FORMAT\0"
/*  1317 */ "format\0"
/*  1324 */ "Separation string - follows all but last\0"
/*  1365 */ "SEPARATION\0"
/*  1376 */ "separation\0"
/*  1387 */ "string at end of all lines but last\0"
/*  1423 */ "LINE_SEPARATION\0"
/*  1439 */ "line-separation\0"
/*  1455 */ "string at end of last line\0"
/*  1482 */ "ENDING\0"
/*  1489 */ "ending\0"
/*  1496 */ "Specify the ordering of the entries:\0"
/*  1533 */ "Print entries in column order\0"
/*  1563 */ "BY_COLUMNS\0"
/*  1574 */ "by-columns\0"
/*  1585 */ "Sort input text\0"
/*  1601 */ "SORT\0"
/*  1606 */ "sort\0"
/*  1611 */ "Redirecting stdin to an alternate file:\0"
/*  1651 */ "Input file (if not stdin)\0"
/*  1677 */ "INPUT\0"
/*  1683 */ "input\0"
/*  1689 */ "display extended usage information and exit\0"
/*  1733 */ "help\0"
/*  1738 */ "extended usage information passed thru pager\0"
/*  1783 */ "more-help\0"
/*  1793 */ "output version information and exit\0"
/*  1829 */ "version\0"
/*  1837 */ "save the option state to a config file\0"
/*  1876 */ "save-opts\0"
/*  1886 */ "load options from a config file\0"
/*  1918 */ "LOAD_OPTS\0"
/*  1928 */ "no-load-opts\0"
/*  1941 */ "no\0"
/*  1944 */ "columns (GNU AutoGen) - Columnize Input Text - Ver. 1.2\n"
            "Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n\0"
/*  2058 */ ".\0"
/*  2060 */ "$HOME\0"
/*  2066 */ ".columnsrc\0"
/*  2077 */ "autogen-users@lists.sourceforge.net\0"
/*  2113 */ "columns (GNU AutoGen) 1.2";

/**
 *  dimensions option description:
 */
/** dimensions option separation text */
#define DIMENSIONS_DESC      (columns_opt_strs+897)
#define DIMENSIONS_FLAGS     (OPTST_DOCUMENT | OPTST_NO_INIT)

/**
 *  width option description:
 */
/** Descriptive text for the width option */
#define WIDTH_DESC      (columns_opt_strs+928)
/** Upper-cased name for the width option */
#define WIDTH_NAME      (columns_opt_strs+947)
/** Name string for the width option */
#define WIDTH_name      (columns_opt_strs+953)
/** The compiled in default value for the width option argument */
#define WIDTH_DFT_ARG   ((char const*)79)
/** Compiled in flag settings for the width option */
#define WIDTH_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/**
 *  columns option description:
 */
/** Descriptive text for the columns option */
#define COLUMNS_DESC      (columns_opt_strs+959)
/** Upper-cased name for the columns option */
#define COLUMNS_NAME      (columns_opt_strs+985)
/** Name string for the columns option */
#define COLUMNS_name      (columns_opt_strs+993)
/** The compiled in default value for the columns option argument */
#define COLUMNS_DFT_ARG   ((char const*)0)
/** Compiled in flag settings for the columns option */
#define COLUMNS_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/**
 *  col_width option description:
 */
/** Descriptive text for the col_width option */
#define COL_WIDTH_DESC      (columns_opt_strs+1001)
/** Upper-cased name for the col_width option */
#define COL_WIDTH_NAME      (columns_opt_strs+1026)
/** Name string for the col_width option */
#define COL_WIDTH_name      (columns_opt_strs+1036)
/** The compiled in default value for the col_width option argument */
#define COL_WIDTH_DFT_ARG   ((char const*)0)
/** Compiled in flag settings for the col_width option */
#define COL_WIDTH_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/**
 *  tab_width option description:
 */
/** Descriptive text for the tab_width option */
#define TAB_WIDTH_DESC      (columns_opt_strs+1046)
/** Upper-cased name for the tab_width option */
#define TAB_WIDTH_NAME      (columns_opt_strs+1056)
/** Name string for the tab_width option */
#define TAB_WIDTH_name      (columns_opt_strs+1066)
/** The compiled in default value for the tab_width option argument */
#define TAB_WIDTH_DFT_ARG   ((char const*)8)
/** Compiled in flag settings for the tab_width option */
#define TAB_WIDTH_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/**
 *  treatment option description:
 */
/** treatment option separation text */
#define TREATMENT_DESC      (columns_opt_strs+1076)
#define TREATMENT_FLAGS     (OPTST_DOCUMENT | OPTST_NO_INIT)

/**
 *  spread option description:
 */
/** Descriptive text for the spread option */
#define SPREAD_DESC      (columns_opt_strs+1109)
/** Upper-cased name for the spread option */
#define SPREAD_NAME      (columns_opt_strs+1146)
/** Name string for the spread option */
#define SPREAD_name      (columns_opt_strs+1153)
/** The compiled in default value for the spread option argument */
#define SPREAD_DFT_ARG   ((char const*)0)
/** Compiled in flag settings for the spread option */
#define SPREAD_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/**
 *  fill option description with
 *  "Must also have options" and "Incompatible options":
 */
/** Descriptive text for the fill option */
#define FILL_DESC      (columns_opt_strs+1160)
/** Upper-cased name for the fill option */
#define FILL_NAME      (columns_opt_strs+1182)
/** Name string for the fill option */
#define FILL_name      (columns_opt_strs+1187)
/** Other options that appear in conjunction with the fill option */
static int const aFillCantList[] = {
    INDEX_OPT_SPREAD,
    INDEX_OPT_COL_WIDTH,
    INDEX_OPT_BY_COLUMNS, NO_EQUIVALENT };
/** Compiled in flag settings for the fill option */
#define FILL_FLAGS     (OPTST_DISABLED)

/**
 *  indent option description:
 */
/** Descriptive text for the indent option */
#define INDENT_DESC      (columns_opt_strs+1192)
/** Upper-cased name for the indent option */
#define INDENT_NAME      (columns_opt_strs+1219)
/** Name string for the indent option */
#define INDENT_name      (columns_opt_strs+1226)
/** Compiled in flag settings for the indent option */
#define INDENT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  first_indent option description with
 *  "Must also have options" and "Incompatible options":
 */
/** Descriptive text for the first_indent option */
#define FIRST_INDENT_DESC      (columns_opt_strs+1233)
/** Upper-cased name for the first_indent option */
#define FIRST_INDENT_NAME      (columns_opt_strs+1251)
/** Name string for the first_indent option */
#define FIRST_INDENT_name      (columns_opt_strs+1264)
/** Other options that are required by the first_indent option */
static int const aFirst_IndentMustList[] = {
    INDEX_OPT_INDENT, NO_EQUIVALENT };
/** Compiled in flag settings for the first_indent option */
#define FIRST_INDENT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  format option description:
 */
/** Descriptive text for the format option */
#define FORMAT_DESC      (columns_opt_strs+1277)
/** Upper-cased name for the format option */
#define FORMAT_NAME      (columns_opt_strs+1310)
/** Name string for the format option */
#define FORMAT_name      (columns_opt_strs+1317)
/** Compiled in flag settings for the format option */
#define FORMAT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  separation option description:
 */
/** Descriptive text for the separation option */
#define SEPARATION_DESC      (columns_opt_strs+1324)
/** Upper-cased name for the separation option */
#define SEPARATION_NAME      (columns_opt_strs+1365)
/** Name string for the separation option */
#define SEPARATION_name      (columns_opt_strs+1376)
/** Compiled in flag settings for the separation option */
#define SEPARATION_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  line_separation option description:
 */
/** Descriptive text for the line_separation option */
#define LINE_SEPARATION_DESC      (columns_opt_strs+1387)
/** Upper-cased name for the line_separation option */
#define LINE_SEPARATION_NAME      (columns_opt_strs+1423)
/** Name string for the line_separation option */
#define LINE_SEPARATION_name      (columns_opt_strs+1439)
/** Compiled in flag settings for the line_separation option */
#define LINE_SEPARATION_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  ending option description:
 */
/** Descriptive text for the ending option */
#define ENDING_DESC      (columns_opt_strs+1455)
/** Upper-cased name for the ending option */
#define ENDING_NAME      (columns_opt_strs+1482)
/** Name string for the ending option */
#define ENDING_name      (columns_opt_strs+1489)
/** Compiled in flag settings for the ending option */
#define ENDING_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/**
 *  ordering option description:
 */
/** ordering option separation text */
#define ORDERING_DESC      (columns_opt_strs+1496)
#define ORDERING_FLAGS     (OPTST_DOCUMENT | OPTST_NO_INIT)

/**
 *  by_columns option description:
 */
/** Descriptive text for the by_columns option */
#define BY_COLUMNS_DESC      (columns_opt_strs+1533)
/** Upper-cased name for the by_columns option */
#define BY_COLUMNS_NAME      (columns_opt_strs+1563)
/** Name string for the by_columns option */
#define BY_COLUMNS_name      (columns_opt_strs+1574)
/** Compiled in flag settings for the by_columns option */
#define BY_COLUMNS_FLAGS     (OPTST_DISABLED)

/**
 *  sort option description:
 */
/** Descriptive text for the sort option */
#define SORT_DESC      (columns_opt_strs+1585)
/** Upper-cased name for the sort option */
#define SORT_NAME      (columns_opt_strs+1601)
/** Name string for the sort option */
#define SORT_name      (columns_opt_strs+1606)
/** Compiled in flag settings for the sort option */
#define SORT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | OPTST_ARG_OPTIONAL)

/**
 *  input-text option description:
 */
/** input-text option separation text */
#define INPUT_TEXT_DESC      (columns_opt_strs+1611)
#define INPUT_TEXT_FLAGS     (OPTST_DOCUMENT | OPTST_NO_INIT)

/**
 *  input option description:
 */
/** Descriptive text for the input option */
#define INPUT_DESC      (columns_opt_strs+1651)
/** Upper-cased name for the input option */
#define INPUT_NAME      (columns_opt_strs+1677)
/** Name string for the input option */
#define INPUT_name      (columns_opt_strs+1683)
/** Compiled in flag settings for the input option */
#define INPUT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  Help/More_Help/Version option descriptions:
 */
#define HELP_DESC       (columns_opt_strs+1689)
#define HELP_name       (columns_opt_strs+1733)
#ifdef HAVE_WORKING_FORK
#define MORE_HELP_DESC  (columns_opt_strs+1738)
#define MORE_HELP_name  (columns_opt_strs+1783)
#define MORE_HELP_FLAGS (OPTST_IMM | OPTST_NO_INIT)
#else
#define MORE_HELP_DESC  HELP_DESC
#define MORE_HELP_name  HELP_name
#define MORE_HELP_FLAGS (OPTST_OMITTED | OPTST_NO_INIT)
#endif
#ifdef NO_OPTIONAL_OPT_ARGS
#  define VER_FLAGS     (OPTST_IMM | OPTST_NO_INIT)
#else
#  define VER_FLAGS     (OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | \
                         OPTST_ARG_OPTIONAL | OPTST_IMM | OPTST_NO_INIT)
#endif
#define VER_DESC        (columns_opt_strs+1793)
#define VER_name        (columns_opt_strs+1829)
#define SAVE_OPTS_DESC  (columns_opt_strs+1837)
#define SAVE_OPTS_name  (columns_opt_strs+1876)
#define LOAD_OPTS_DESC     (columns_opt_strs+1886)
#define LOAD_OPTS_NAME     (columns_opt_strs+1918)
#define NO_LOAD_OPTS_name  (columns_opt_strs+1928)
#define LOAD_OPTS_pfx      (columns_opt_strs+1941)
#define LOAD_OPTS_name     (NO_LOAD_OPTS_name + 3)
/**
 *  Declare option callback procedures
 */
extern tOptProc
    optionBooleanVal,   optionNestedVal,    optionNumericVal,
    optionPagedUsage,   optionPrintVersion, optionResetOpt,
    optionStackArg,     optionTimeDate,     optionTimeVal,
    optionUnstackArg,   optionVendorOption;
static tOptProc
    doOptCol_Width, doOptColumns,   doOptInput,     doOptSpread,
    doOptWidth,     doUsageOpt;
#define VER_PROC        optionPrintVersion

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 *  Define the columns Option Descriptions.
 * This is an array of OPTION_CT entries, one for each
 * option that the columns program responds to.
 */
static tOptDesc optDesc[OPTION_CT] = {
  {  /* entry idx, value */ 0, 0,
     /* equiv idx, value */ 0, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 0, 0,
     /* opt state flags  */ DIMENSIONS_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ DIMENSIONS_DESC, NULL, NULL,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 1, VALUE_OPT_WIDTH,
     /* equiv idx, value */ 1, VALUE_OPT_WIDTH,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ WIDTH_FLAGS, 0,
     /* last opt argumnt */ { WIDTH_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptWidth,
     /* desc, NAME, name */ WIDTH_DESC, WIDTH_NAME, WIDTH_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 2, VALUE_OPT_COLUMNS,
     /* equiv idx, value */ 2, VALUE_OPT_COLUMNS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ COLUMNS_FLAGS, 0,
     /* last opt argumnt */ { COLUMNS_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptColumns,
     /* desc, NAME, name */ COLUMNS_DESC, COLUMNS_NAME, COLUMNS_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 3, VALUE_OPT_COL_WIDTH,
     /* equiv idx, value */ 3, VALUE_OPT_COL_WIDTH,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ COL_WIDTH_FLAGS, 0,
     /* last opt argumnt */ { COL_WIDTH_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptCol_Width,
     /* desc, NAME, name */ COL_WIDTH_DESC, COL_WIDTH_NAME, COL_WIDTH_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 4, VALUE_OPT_TAB_WIDTH,
     /* equiv idx, value */ 4, VALUE_OPT_TAB_WIDTH,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ TAB_WIDTH_FLAGS, 0,
     /* last opt argumnt */ { TAB_WIDTH_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionNumericVal,
     /* desc, NAME, name */ TAB_WIDTH_DESC, TAB_WIDTH_NAME, TAB_WIDTH_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 0, 0,
     /* equiv idx, value */ 0, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 0, 0,
     /* opt state flags  */ TREATMENT_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ TREATMENT_DESC, NULL, NULL,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 6, VALUE_OPT_SPREAD,
     /* equiv idx, value */ 6, VALUE_OPT_SPREAD,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ SPREAD_FLAGS, 0,
     /* last opt argumnt */ { SPREAD_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptSpread,
     /* desc, NAME, name */ SPREAD_DESC, SPREAD_NAME, SPREAD_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 7, VALUE_OPT_FILL,
     /* equiv idx, value */ 7, VALUE_OPT_FILL,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ FILL_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --fill */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, aFillCantList,
     /* option proc      */ NULL,
     /* desc, NAME, name */ FILL_DESC, FILL_NAME, FILL_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 8, VALUE_OPT_INDENT,
     /* equiv idx, value */ 8, VALUE_OPT_INDENT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ INDENT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --indent */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ INDENT_DESC, INDENT_NAME, INDENT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 9, VALUE_OPT_FIRST_INDENT,
     /* equiv idx, value */ 9, VALUE_OPT_FIRST_INDENT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ FIRST_INDENT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --first_indent */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ aFirst_IndentMustList, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ FIRST_INDENT_DESC, FIRST_INDENT_NAME, FIRST_INDENT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 10, VALUE_OPT_FORMAT,
     /* equiv idx, value */ 10, VALUE_OPT_FORMAT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ FORMAT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --format */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ FORMAT_DESC, FORMAT_NAME, FORMAT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 11, VALUE_OPT_SEPARATION,
     /* equiv idx, value */ 11, VALUE_OPT_SEPARATION,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ SEPARATION_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --separation */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ SEPARATION_DESC, SEPARATION_NAME, SEPARATION_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 12, VALUE_OPT_LINE_SEPARATION,
     /* equiv idx, value */ 12, VALUE_OPT_LINE_SEPARATION,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LINE_SEPARATION_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --line_separation */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ LINE_SEPARATION_DESC, LINE_SEPARATION_NAME, LINE_SEPARATION_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 13, VALUE_OPT_ENDING,
     /* equiv idx, value */ 13, VALUE_OPT_ENDING,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ ENDING_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --ending */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ ENDING_DESC, ENDING_NAME, ENDING_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 0, 0,
     /* equiv idx, value */ 0, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 0, 0,
     /* opt state flags  */ ORDERING_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ ORDERING_DESC, NULL, NULL,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 15, VALUE_OPT_BY_COLUMNS,
     /* equiv idx, value */ 15, VALUE_OPT_BY_COLUMNS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ BY_COLUMNS_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --by_columns */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ BY_COLUMNS_DESC, BY_COLUMNS_NAME, BY_COLUMNS_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 16, VALUE_OPT_SORT,
     /* equiv idx, value */ 16, VALUE_OPT_SORT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ SORT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --sort */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ SORT_DESC, SORT_NAME, SORT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 0, 0,
     /* equiv idx, value */ 0, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 0, 0,
     /* opt state flags  */ INPUT_TEXT_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ INPUT_TEXT_DESC, NULL, NULL,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 18, VALUE_OPT_INPUT,
     /* equiv idx, value */ 18, VALUE_OPT_INPUT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ INPUT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --input */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptInput,
     /* desc, NAME, name */ INPUT_DESC, INPUT_NAME, INPUT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_VERSION, VALUE_OPT_VERSION,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_VERSION,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ VER_FLAGS, AOUSE_VERSION,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ VER_PROC,
     /* desc, NAME, name */ VER_DESC, NULL, VER_name,
     /* disablement strs */ NULL, NULL },



  {  /* entry idx, value */ INDEX_OPT_HELP, VALUE_OPT_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_IMM | OPTST_NO_INIT, AOUSE_HELP,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doUsageOpt,
     /* desc, NAME, name */ HELP_DESC, NULL, HELP_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_MORE_HELP, VALUE_OPT_MORE_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_MORE_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ MORE_HELP_FLAGS, AOUSE_MORE_HELP,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL,  NULL,
     /* option proc      */ optionPagedUsage,
     /* desc, NAME, name */ MORE_HELP_DESC, NULL, MORE_HELP_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_SAVE_OPTS, VALUE_OPT_SAVE_OPTS,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_SAVE_OPTS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_SET_ARGTYPE(OPARG_TYPE_STRING)
                       | OPTST_ARG_OPTIONAL | OPTST_NO_INIT, AOUSE_SAVE_OPTS,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL,  NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ SAVE_OPTS_DESC, NULL, SAVE_OPTS_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_LOAD_OPTS, VALUE_OPT_LOAD_OPTS,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_LOAD_OPTS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ OPTST_SET_ARGTYPE(OPARG_TYPE_STRING)
			  | OPTST_DISABLE_IMM, AOUSE_LOAD_OPTS,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionLoadOpt,
     /* desc, NAME, name */ LOAD_OPTS_DESC, LOAD_OPTS_NAME, LOAD_OPTS_name,
     /* disablement strs */ NO_LOAD_OPTS_name, LOAD_OPTS_pfx }
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/** Reference to the upper cased version of columns. */
#define zPROGNAME       (columns_opt_strs+985)
/** Reference to the title line for columns usage. */
#define zUsageTitle     (columns_opt_strs+1944)
/** columns configuration file name. */
#define zRcName         (columns_opt_strs+2066)
/** Directories to search for columns config files. */
static char const * const apzHomeList[3] = {
    columns_opt_strs+2058,
    columns_opt_strs+2060,
    NULL };
/** The columns program bug email address. */
#define zBugsAddr       (columns_opt_strs+2077)
/** Clarification/explanation of what columns does. */
#define zExplain        (NULL)
/** Extra detail explaining what columns does. */
#define zDetail         (NULL)
/** The full version string for columns. */
#define zFullVersion    (columns_opt_strs+2113)
/* extracted from optcode.tlib near line 364 */

#define OPTPROC_BASE OPTPROC_NONE
#define translate_option_strings NULL

#define columns_full_usage (NULL)
#define columns_short_usage (NULL)

#endif /* not defined __doxygen__ */

/*
 *  Create the static procedure(s) declared above.
 */
/**
 * The callout function that invokes the optionUsage function.
 *
 * @param[in] opts the AutoOpts option description structure
 * @param[in] od   the descriptor for the "help" (usage) option.
 * @noreturn
 */
static void
doUsageOpt(tOptions * opts, tOptDesc * od)
{
    int ex_code;
    ex_code = COLUMNS_EXIT_SUCCESS;
    optionUsage(&columnsOptions, ex_code);
    /* NOTREACHED */
    (void)opts;
    (void)od;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the width option.
 * This option specifies the full width of the output line,
 * including any start-of-line indentation.  The output will fill
 * each line as completely as possible, unless the column width has
 * been explicitly specified.  If the maximum width is less than
 * the length of the widest input, you will get a single column
 * of output.
 * @param[in] pOptions the columns options data structure
 * @param[in,out] pOptDesc the option descriptor for this option.
 */
static void
doOptWidth(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 16, 4095 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

 emit_ranges:
    optionShowRange(pOptions, pOptDesc, (void *)rng, 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the columns option.
 * Use this option to specify exactly how many columns to produce.
 * If that many columns will not fit within @var{line_width}, then
 * the count will be reduced to the number that fit.
 * @param[in] pOptions the columns options data structure
 * @param[in,out] pOptDesc the option descriptor for this option.
 */
static void
doOptColumns(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 1, 2048 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

 emit_ranges:
    optionShowRange(pOptions, pOptDesc, (void *)rng, 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the col_width option.
 * Use this option to specify exactly how many characters are to be
 * allocated for each column.  If it is narrower than the widest entry,
 * it will be over-ridden with the required width.
 * @param[in] pOptions the columns options data structure
 * @param[in,out] pOptDesc the option descriptor for this option.
 */
static void
doOptCol_Width(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 1, 2048 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

 emit_ranges:
    optionShowRange(pOptions, pOptDesc, (void *)rng, 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the spread option.
 * Use this option to specify exactly how many characters may be
 * added to each column.  It allows you to prevent columns from
 * becoming too far apart.  Without this option, @file{columns}
 * will attempt to widen columns to fill the full width.
 * @param[in] pOptions the columns options data structure
 * @param[in,out] pOptDesc the option descriptor for this option.
 */
static void
doOptSpread(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 1, 1024 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

 emit_ranges:
    optionShowRange(pOptions, pOptDesc, (void *)rng, 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the input option.
 * This program normally runs as a @code{filter}, reading from standard
 * input, columnizing and writing to standard out.  This option redirects
 * input to a file.
 * @param[in] pOptions the columns options data structure
 * @param[in,out] pOptDesc the option descriptor for this option.
 */
static void
doOptInput(tOptions* pOptions, tOptDesc* pOptDesc)
{
    /*
     * Be sure the flag-code[0] handles special values for the options pointer
     * viz. (poptions <= OPTPROC_EMIT_LIMIT) *and also* the special flag bit
     * ((poptdesc->fOptState & OPTST_RESET) != 0) telling the option to
     * reset its state.
     */
    /* extracted from opts.def, line 304 */
    FILE* fp = freopen(
        pOptDesc->optArg.argString, "r" FOPEN_BINARY_FLAG, stdin);

    if (fp == (FILE*)NULL) {
        fprintf(stderr, OPEN_ERROR_FMT, errno, strerror(errno),
                pOptDesc->optArg.argString);
        USAGE(EXIT_FAILURE);
    }
    (void)pOptions;
}
/* extracted from optmain.tlib near line 1266 */

/**
 * The directory containing the data associated with columns.
 */
#ifndef  PKGDATADIR
# define PKGDATADIR ""
#endif

/**
 * Information about the person or institution that packaged columns
 * for the current distribution.
 */
#ifndef  WITH_PACKAGER
# define columns_packager_info NULL
#else
/** Packager information for columns. */
static char const columns_packager_info[] =
    "Packaged by " WITH_PACKAGER

# ifdef WITH_PACKAGER_VERSION
        " ("WITH_PACKAGER_VERSION")"
# endif

# ifdef WITH_PACKAGER_BUG_REPORTS
    "\nReport columns bugs to " WITH_PACKAGER_BUG_REPORTS
# endif
    "\n";
#endif
#ifndef __doxygen__

#endif /* __doxygen__ */
/**
 * The option definitions for columns.  The one structure that
 * binds them all.
 */
tOptions columnsOptions = {
    OPTIONS_STRUCT_VERSION,
    0, NULL,                    /* original argc + argv    */
    ( OPTPROC_BASE
    + OPTPROC_ERRSTOP
    + OPTPROC_SHORTOPT
    + OPTPROC_LONGOPT
    + OPTPROC_NO_REQ_OPT
    + OPTPROC_ENVIRON
    + OPTPROC_NO_ARGS ),
    0, NULL,                    /* current option index, current option */
    NULL,         NULL,         zPROGNAME,
    zRcName,      zCopyright,   zLicenseDescrip,
    zFullVersion, apzHomeList,  zUsageTitle,
    zExplain,     zDetail,      optDesc,
    zBugsAddr,                  /* address to send bugs to */
    NULL, NULL,                 /* extensions/saved state  */
    optionUsage, /* usage procedure */
    translate_option_strings,   /* translation procedure */
    /*
     *  Indexes to special options
     */
    { INDEX_OPT_MORE_HELP, /* more-help option index */
      INDEX_OPT_SAVE_OPTS, /* save option index */
      NO_EQUIVALENT, /* '-#' option index */
      NO_EQUIVALENT /* index of default opt */
    },
    24 /* full option count */, 19 /* user option count */,
    columns_full_usage, columns_short_usage,
    NULL, NULL,
    PKGDATADIR, columns_packager_info
};

#ifdef  __cplusplus
}
#endif
/** @} */
/* opts.c ends here */
