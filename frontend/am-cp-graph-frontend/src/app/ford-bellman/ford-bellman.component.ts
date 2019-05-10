import { Component, OnInit } from '@angular/core';
import {FormBuilder, FormGroup, Validators} from '@angular/forms';
import {SendDataService} from '../send-data.service';

@Component({
  selector: 'app-ford-bellman',
  templateUrl: './ford-bellman.component.html',
  styleUrls: ['./ford-bellman.component.css']
})
export class FordBellmanComponent implements OnInit {

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
    this.sendDataService.bellman(this.task.value.task).subscribe(res => {
      console.log(res.answer);
      this.isLoad = true;
      this.res = res.answer;
      this.task.reset();
    });
  }
}
