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

#pragma once

// SplitAlignment: paramenters related to split alignment
class CSplitAlignmentUtilities {
public:
	// toggles if we should filter partial alignments with too many mismatches (count)
	static bool UseMismatchFilter;
	// toggles if we should filter partial alignments with too many mismatches (percent)
	static bool UseMismatchPercentFilter;
	// sets the maximum number of mismatches to allow if the mismatch filter is enabled
	static unsigned int MaxNumMismatches;
	// sets the maximum mismatch percent to allow if the mismatch percent filter is enabled
	static double MaxMismatchPercent;
	// toggles if we should filter partial alignments that match too little of the original sequence (count)
	static bool UseMinAlignmentFilter;
        // toggles if we should filter partial alignments that match too little of the original sequence (percent)
        static bool UseMinAlignmentPercentFilter;
	// sets the minimum number of aligned nucleotides to allow if the minimum alignment filter is enabled
	static unsigned int MinAlignment;
	// sets the minimum percentage of alignment to allow if the minimum alignment filter is enabled
	static double MinAlignmentPercent;
        // toggle if we have the search radius for the first partial alignment
        static bool HasFirstPartialRadius;
        // toggle if we have the search radius for the second partial alignment
        static bool HasSecondPartialRadius;
        // the search raidus for the first partial alignment
        static unsigned int FirstPartialRadius;
        // the search radius for the second partial alignment
        static unsigned int SecondPartialRadius;

        // TODO:calculate the alignment quality for split alignment
	// toggles if we should filter sequences that have low alignment qualities
	static bool UseMinAlignmentQualityFilter;
	// sets the minimum aligment quality to allow if the minimum alignment quality filter is enabled
	static unsigned char MinAlignmentQuality;
};
