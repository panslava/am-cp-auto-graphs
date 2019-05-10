import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import {Observable} from 'rxjs';
import {IAnswer} from './models';

@Injectable({
  providedIn: 'root'
})
export class SendDataService {

  constructor(private http: HttpClient) { }

  strongConnected(data: string): Observable<IAnswer> {
    return this.http.post<IAnswer>('/api/strong', {data});
  }

  matchings(data: string): Observable<IAnswer> {
    return this.http.post<IAnswer>('/api/matchings', {data});
  }

  bellman(data: string): Observable<IAnswer> {
    return this.http.post<IAnswer>('/api/bellman', {data});
  }

  dijkstra(data: string): Observable<IAnswer> {
    return this.http.post<IAnswer>('/api/dijkstra', {data});
  }

  kruskal(data: string): Observable<IAnswer> {
    return this.http.post<IAnswer>('/api/kruskal', {data});
  }

  mincut(data: string): Observable<IAnswer> {
    return this.http.post<IAnswer>('/api/mincut', {data});
  }

  maxflow(data: string): Observable<IAnswer> {
    return this.http.post<IAnswer>('/api/maxflow', {data});
  }

  mincost_maxflow(data: string): Observable<IAnswer> {
    return this.http.post<IAnswer>('/api/mincost_maxflow', {data});
  }

  china(data: string): Observable<IAnswer> {
    return this.http.post<IAnswer>('/api/china', {data});
  }
}
