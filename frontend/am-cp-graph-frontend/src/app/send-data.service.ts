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
}
