import { Component, OnInit } from '@angular/core';
import {FormBuilder, FormGroup, Validators} from '@angular/forms';
import {SendDataService} from '../send-data.service';

@Component({
  selector: 'app-mincost-maxflow',
  templateUrl: './mincost-maxflow.component.html',
  styleUrls: ['./mincost-maxflow.component.css']
})
export class MincostMaxflowComponent implements OnInit {

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
    this.sendDataService.mincost_maxflow(this.task.value.task).subscribe(res => {
      this.isLoad = true;
      this.res = res.answer;
      this.task.reset();
    });
  }
}
