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


    /*
    for (const auto& span : combined){
        std::cout << span << '\n';
    }
    for(auto span : input){
        // Check if there are any overlaps.
        // TODO Refactor loop to deal with iterator invalidation.
        for(auto& cspan : combined){
            // no overlap
            if((span.end < cspan.start) || (span.start > cspan.end)){
//                std::cout << "No overlap \n";
                combined.push_back(span);
                continue;
            }
            // complete overlap
            if((cspan.start <= span.start) && (cspan.end >= span.end)){
//                std::cout << "Complete overlap \n";
                continue;
            }
            // partial overlaps
            // Target span expands combined span to left
            if((span.start < cspan.start) && (span.end >= cspan.start) && (span.end <= cspan.end)){
//                std::cout << "Expand Left\n";
               cspan.start = span.start;
            }
            // Target span expands combined span to the right
            if((span.end > cspan.end) && (span.start >= cspan.start) && (span.start <= cspan.end)){
//                std::cout << "Expand Right\n";
                cspan.end = span.end;
            }
        }

        // Finally, recheck all ranges for any overlap

    }
    for (const auto& span : combined){
        std::cout << span << '\n';
    }
     */
    return combined;
}