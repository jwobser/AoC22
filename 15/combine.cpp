//
// Created by James Wobser on 12/17/2022.
//

#include "combine.h"

std::vector<ExclusionSpan> combine_exclusions(std::vector<ExclusionSpan> input){
    std::vector<ExclusionSpan> combined;
    combined.reserve(input.size());
    combined.push_back(input[0]);

    for(int j{1}; j < input.size(); ++j){
        auto inspan = input[j];
        int instart = inspan.start;
        int inend = inspan.end;
        for(int k{0}; k < combined.size(); ++k){
            auto combinedstart = combined[k].start;
            auto combinedend = combined[k].end;
            // Expand Left
            if((instart < combinedstart) && (inend >= combinedstart) && (inend <= combinedend)){
                combined[k].start = instart;
                continue;
            }
            // Expand Right
            if((inend > combinedend) && (instart >= combinedstart) && (instart <= combinedend)){
                combined[k].end = inend;
                continue;
            }

            // Complete Overlap
            if((instart < combinedstart) && (inend > combinedend)){
                combined[k].start = instart;
                combined[k].end = inend;
                break;
            }

            // No Overlap
            if((inend < combinedstart) || (instart > combinedend)){
                combined.push_back(inspan);
                break;
            }

        }
    }

    return combined;
}