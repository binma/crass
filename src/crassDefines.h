
// File: crass_defines.h
// Original Author: Connor Skennerton on 7/05/11
// --------------------------------------------------------------------
//
// OVERVIEW:
//
// The one stop shop for all your global definition needs!
// 
// --------------------------------------------------------------------
//  Copyright  2011 Michael Imelfort and Connor Skennerton
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
// --------------------------------------------------------------------
//
//                        A
//                       A B
//                      A B R
//                     A B R A
//                    A B R A C
//                   A B R A C A
//                  A B R A C A D
//                 A B R A C A D A
//                A B R A C A D A B 
//               A B R A C A D A B R  
//              A B R A C A D A B R A 
//
// --------------------------------------------------------------------

#ifndef __CRASSDEFINES_H
    #define __CRASSDEFINES_H

#include <string>
#include <getopt.h>
// --------------------------------------------------------------------
 // STRING LENGTH / MISMATCH / CLUSTER SIZE PARAMETERS
// --------------------------------------------------------------------
#define CRASS_DEF_READ_LENGTH_CUTOFF            (200.0)             // The length of read where the multipattern matcher would become insignificant. 
                                                                    //   ie where it is very likely that there is 2 full repeat-spacer-repeat units
#define CRASS_DEF_MAX_PATTERN_LENGTH            1024                // How long can a DR be?
#define CRASS_DEF_MAX_LOST_SOULS_MISMATCHES     2
#define CRASS_DEF_MAX_CLUSTER_SIZE_FOR_SW       30                  // Maximum number of cluster reps we will all vs all sw for
#define CRASS_DEF_MIN_SW_ALIGNMENT_RATIO        (0.85)              // SW alignments need to be this percentage of the original query to be considered real
#define CRASS_DEF_SW_SEARCH_EXT                 8
#define CRASS_DEF_LOW_COMPLEXITY_THRESHHOLD     (0.75)
#define CRASS_DEF_KMER_SIZE                     7
#define CRASS_DEF_K_CLUST_MIN                   12
// --------------------------------------------------------------------
// HARD CODED PARAMS FOR FINDING TRUE DRs
// --------------------------------------------------------------------
#define CRASS_DEF_PERCENT_IN_ZONE_CUT_OFF       (0.85)              // amount that a DR must agrre with the existsing DR within a zone to be added
#define CRASS_DEF_NUM_KMERS_4_MODE              (5)                 // find the top XX occuring in the DR
#define CRASS_DEF_NUM_KMERS_4_MODE_HALF         (CRASS_DEF_NUM_KMERS_4_MODE - (CRASS_DEF_NUM_KMERS_4_MODE/2)) // Ceil of 50% of CRASS_DEF_NUM_KMERS_4_MODE
#define CRASS_DEF_MIN_READ_DEPTH                2                   // read depth used for consensus building
#define CRASS_DEF_CONS_CUT_OFF                  (0.80)              // minimum identity to extend a DR from the "zone" outwards
#define CRASS_DEF_COLLAPSED_THRESHOLD           (0.30)              // in the event that clustering has collapsed two DRs into one, this number is used to plait them apart
#define CRASS_DEF_PARTIAL_SIM_CUT_OFF           (0.85)              // The similarity needed to exted into partial matches
#define CRASS_DEF_DR_ZONE_TRIM_AMOUNT           (3)                 // trim this many bases off the start and end of the DR
// --------------------------------------------------------------------
// GENOME ALGORITHM DEFINES
// --------------------------------------------------------------------
#define CRASS_DEF_SPACER_OR_REPEAT_MAX_SIMILARITY  (0.82)
#define CRASS_DEF_SPACER_TO_SPACER_LENGTH_DIFF     12
#define CRASS_DEF_SPACER_TO_REPEAT_LENGTH_DIFF     30
#define CRASS_DEF_MIN_SEARCH_WINDOW_LENGTH         6
#define CRASS_DEF_MAX_SEARCH_WINDOW_LENGTH         9
#define CRASS_DEF_OPTIMAL_SEARCH_WINDOW_LENGTH     8
#define CRASS_DEF_SCAN_LENGTH                      30
#define CRASS_DEF_SCAN_CONFIDENCE                  (0.70)
#define CRASS_DEF_TRIM_EXTEND_CONFIDENCE           (0.5)
#define CRASS_DEF_DEFAULT_MIN_NUM_REPEATS          3
// --------------------------------------------------------------------
  // FILE IO
// --------------------------------------------------------------------
#define CRASS_DEF_FASTQ_FILENAME_MAX_LENGTH     1024
#define CRASS_DEF_DEF_KMER_LOOKUP_EXT           "crass_kmers.txt"
#define CRASS_DEF_DEF_PATTERN_LOOKUP_EXT        "crass_direct_repeats.txt"
#define CRASS_DEF_DEF_SPACER_LOOKUP_EXT         "crass_spacers.txt"
// --------------------------------------------------------------------
// GRAPH BUILDING
// --------------------------------------------------------------------
#define CRASS_DEF_NODE_KMER_SIZE                9                   // size of the kmer that defines a crispr node
// --------------------------------------------------------------------
 // USER OPTION STRUCTURE
// --------------------------------------------------------------------
#define CRASS_DEF_STATS_REPORT_DELIM            "\t"                // delimiter string for stats report
#define CRASS_DEF_MIN_DR_SIZE                   23                  // minimum direct repeat size
#define CRASS_DEF_MAX_DR_SIZE                   45                  // maximum direct repeat size
#define CRASS_DEF_MIN_SPACER_SIZE               26                  // minimum spacer size
#define CRASS_DEF_MAX_SPACER_SIZE               50                  // maximum spacer size
#define CRASS_DEF_NUM_DR_ERRORS                 0                   // maxiumum allowable errors in direct repeat
#define CRASS_DEF_MAX_DEBUG_LOGGING             10
#define CRASS_DEF_MAX_LOGGING                   4
#define CRASS_DEF_DEFAULT_LOGGING               1

typedef struct {
    bool                detect;                                             // print reads and exit after find
    int                 logLevel;                                           // level of verbosity allowed in the log file
    bool                reportStats;                                        // print a starts report currently not used
    unsigned int        lowDRsize;                                          // the lower size limit for a direct repeat
    unsigned int        highDRsize;                                         // the upper size limit for a direct repeat
    unsigned int        lowSpacerSize;                                      // the lower limit for a spacer
    unsigned int        highSpacerSize;                                     // the upper size limit for a spacer
    std::string         output_fastq;                                       // the output directory for the output files
    std::string         delim;                                              // delimiter used in stats report currently not used
    int                 kmer_size;                                          // number of kmers needed to be shared to add to a cluser
    unsigned int        searchWindowLength;                                 // option 'w'used in long read search only
    unsigned int        minNumRepeats;                                      // option 'n'used in long read search only
    bool                logToScreen;
    bool                removeHomopolymers;
} options;

//enum SequenceType {
//    sanger,
//    fourFiveFour,
//    illumina
//    };



// --------------------------------------------------------------------
#endif // __CRASSDEFINES_H