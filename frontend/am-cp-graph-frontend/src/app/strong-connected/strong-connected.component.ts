import { Component, OnInit } from '@angular/core';
import {FormBuilder, FormGroup, Validators} from '@angular/forms';
import {SendDataService} from '../send-data.service';

@Component({
  selector: 'app-strong-connected',
  templateUrl: './strong-connected.component.html',
  styleUrls: ['./strong-connected.component.css']
})
export class StrongConnectedComponent implements OnInit {


  private task: FormGroup;
  isLoad = false;
  res;

  constructor(private fb: FormBuilder, private sendDataService: SendDataService) { }

  ngOnInit() {
    this.task = this.fb.group({
      task: ['', [Validators.required]]
    });

  }

  sendData() {
    this.sendDataService.strongConnected(this.task.value.task).subscribe(res => {
      this.isLoad = true;
      this.res = res.answer;
      this.task.reset();
    });
  }
}
