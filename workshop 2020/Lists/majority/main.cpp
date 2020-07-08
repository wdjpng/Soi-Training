#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> votes;

    for (int i = 0; i < n; ++i) {
        int vote;
        cin >> vote;

        if(votes.find(vote) == votes.end()){
            votes.insert({vote, 1});
        } else{
            votes[vote]++;
        }
    }

    int sum = 0;
    int maxVoteParty = -1;
    int maxVotes = -1;
    for(map<int, int>::iterator iter = votes.begin(); iter != votes.end(); ++iter)
    {
        pair<int, int> party = *iter;

        sum+=party.second;
        if(party.second > maxVotes){
            maxVoteParty = party.first;
            maxVotes = party.second;
        }
    }

    if(maxVotes > sum / 2.0){
        cout << maxVoteParty << "\n";
    } else{
        cout << "NO\n";
    }
}