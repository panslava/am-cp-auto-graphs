import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { ListOfTasksComponent } from './list-of-tasks/list-of-tasks.component';
import { StrongConnectedComponent } from './strong-connected/strong-connected.component';
import { ReactiveFormsModule } from '@angular/forms';
import { SendDataService } from './send-data.service';
import { HttpClientModule } from '@angular/common/http';
import { MatchingsComponent } from './matchings/matchings.component';

@NgModule({
  declarations: [
    AppComponent,
    ListOfTasksComponent,
    StrongConnectedComponent,
    MatchingsComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    ReactiveFormsModule
  ],
  providers: [SendDataService],
  bootstrap: [AppComponent]
})
export class AppModule { }
