int M;  // number of vertex
int N;  // number of edge
int s, t, w;

struct Edge{

    int t, w;

    bool operator < (const Edge &rhs) const {
        return w > rhs.w;
    }
};

int dis[100001];
vector<Edge> G[100001];

void Dijkstra(int s){

    for(int i = 0; i <= M; i++){
        dis[i] = 1e9;
    }

    dis[s] = 0;
    priority_queue<Edge> pq;

    pq.push({s, 0});

    while(!pq.empty()){

        Edge now = pq.top();
        pq.pop();

        if(now.w > dis[now.t]){
            continue;
        }

        // relax
        for(Edge e: G[now.t]){
            if(dis[e.t] > now.w + e.w){
                dis[e.t] = now.w + e.w;
                pq.push({e.t, dis[e.t]});
            }
        }
    }
}