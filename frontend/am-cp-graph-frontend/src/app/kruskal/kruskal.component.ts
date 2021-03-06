import { Component, OnInit } from '@angular/core';
import {FormBuilder, FormGroup, Validators} from '@angular/forms';
import {SendDataService} from '../send-data.service';

@Component({
  selector: 'app-kruskal',
  templateUrl: './kruskal.component.html',
  styleUrls: ['./kruskal.component.css']
})
export class KruskalComponent implements OnInit {

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
    this.sendDataService.kruskal(this.task.value.task).subscribe(res => {
      this.isLoad = true;
      this.res = res.answer;
    });
  }
}
