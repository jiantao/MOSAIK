// ***************************************************************************
// CSplitAlignmentUtilities - a centralized location for all parameters related 
//                            to split alignment routines.
// ---------------------------------------------------------------------------
// (c) 2006 - 2009  Michael Strömberg
// Marth Lab, Department of Biology, Boston College
// ---------------------------------------------------------------------------
// Dual licenced under the GNU General Public License 2.0+ license or as
// a commercial license with the Marth Lab.
// ***************************************************************************

#include "SplitAlignmentUtilities.h"

// toggles if we should filter partial alignments with too many mismatches (count)
bool CSplitAlignmentUtilities::UseMismatchFilter = false
unsigned int CSplitAlignmentUtilities::MaxNumMismatches = -1;

// toggles if we should filter partial alignments with too many mismatches (percent)
bool CSplitAlignmentUtilities::UseMismatchPercentFilter   = false;
double CSplitAlignmentUtilities::MaxMismatchPercent       = 1.0f;

// toggles if we should filter partial alignments that match too little of the original sequence (count)
bool CSplitAlignmentUtilities::UseMinAlignmentFilter = false;
unsigned int CSplitAlignmentUtilities::MinAlignment  = 0;

// toggles if we should filter partial alignments that match too little of the original sequence (count)
bool CSplitAlignmentUtilities::UseMinAlignmentPercentFilter = false;
double CSplitAlignmentUtilities::MinAlignmentPercent        = 0.0f;

// toggle if we have the search radius for the first partial alignment
bool CSplitAlignmentUtilities::HasFirstPartialRadius      = false;
unsigned int CSplitAlignmentUtilities::FirstPartialRadius = 0; 

// toggle if we have the search radius for the second partial alignment
bool CSplitAlignmentUtilities::HasSecondPartialRadius      = false;
unsigned int CSplitAlignmentUtilities::SecondPartialRadius = 1000000;
