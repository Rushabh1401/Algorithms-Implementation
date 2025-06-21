#include <bits/stdc++.h>
using namespace std;

//LEGENDRY PROBLEM
//ESP. OPTIMSATION USING SET AT LAST MOMENT

int main(){
    int n;
    int m;
    
    cin>>n>>m;
    
    vector<vector<pair<int,int>>>adj(n+1);
    
    for(int i=0 ; i<m ; i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	adj[a].push_back({b,c});
    }
    
    set<tuple<long long,int,bool>>s;
    vector<vector<long long>>dis(n+1, vector<long long>(2,LONG_LONG_MAX));
    
    vector<vector<pair<int,int>>>par(n+1,vector<pair<int,int>>(2));
    par[1][0] = {0,0};
    par[1][1] = {0,0};
    
    s.insert({0,1,false}); //dis,src
    dis[1][0] = 0;
    dis[1][1] = 0;
    
    while(!s.empty()){
    	auto [dist, ele, couponUsed] = *(s.begin());
    	s.erase(*(s.begin()));
    	
    	for(auto child : adj[ele]){
    		
    		int childEle = child.first;
    		int edgeDis = child.second;
    		
    		//min dis to reach childEle without coupon
    		if(!couponUsed && dis[childEle][0] > dis[ele][0] + edgeDis){
    			
    			if(dis[childEle][0] != LONG_LONG_MAX) s.erase({dis[childEle][0] , childEle, false});
    				
    			dis[childEle][0] = dis[ele][0] + edgeDis;
    			s.insert({dis[childEle][0] , childEle, false});
    			par[childEle][0] = {ele,0};	
    		}
    		
    		//min dis to reach childEle without coupon but will use coupon now
    		if(!couponUsed && dis[childEle][1]> dis[ele][0] + (edgeDis/2)){
    			
    			if(dis[childEle][1] != LONG_LONG_MAX) s.erase({dis[childEle][1] , childEle, true});
    				
    			dis[childEle][1] = dis[ele][0] + (edgeDis/2);
    			s.insert({dis[childEle][1] , childEle, true});
    			par[childEle][1] = {ele,0};
    		}
    			
    		if(couponUsed && dis[childEle][1]> dis[ele][1] + edgeDis){
    			
    			if(dis[childEle][1] != LONG_LONG_MAX) s.erase({dis[childEle][1] , childEle, true});
    			
    			dis[childEle][1] = dis[ele][1] + edgeDis;
    			s.insert({dis[childEle][1] , childEle, true});
    			par[childEle][1] = {ele,1};	
    		}	
    	}
    }
   
    cout<<dis[n][1]<<endl;
    
    cout<<"Route Race"<<endl;
    
    pair<int,int>curr = {n,1};
    
    while(curr.first>=1){
    	auto [currEle, couponUsed] = curr;
    	
    	cout<<currEle<<" ";
    	
    	if(couponUsed) cout<<"Coupon Used";
    	
    	cout<<endl;
    	
    	curr = par[currEle][couponUsed];
    }
}
