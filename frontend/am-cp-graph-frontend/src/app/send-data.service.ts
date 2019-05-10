import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import {Observable} from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class SendDataService {

  constructor(private http: HttpClient) { }

  strongConnected(data: string): Observable<object> {
    return this.http.post('api/strong', {data});
  }
}
