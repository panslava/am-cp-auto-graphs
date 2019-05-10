import { Component, OnInit } from '@angular/core';
import {FormBuilder, FormGroup, Validators} from '@angular/forms';
import {SendDataService} from '../send-data.service';

@Component({
  selector: 'app-matchings',
  templateUrl: './matchings.component.html',
  styleUrls: ['./matchings.component.css']
})
export class MatchingsComponent implements OnInit {

  task: FormGroup;
  isLoad = false;
  res;

  constructor(private fb: FormBuilder, private sendDataService: SendDataService) { }

  ngOnInit() {
    this.task = this.fb.group({
      task: ['', [Validators.required]]
    });

  }

  sendData() {
    this.sendDataService.matchings(this.task.value.task).subscribe(res => {
      this.isLoad = true;
      this.res = res.answer;
      this.task.reset();
    });
  }

}
